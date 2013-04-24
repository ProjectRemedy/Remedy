<?php
/**
 * @file
 * Bundle Inherit features include fiel.
 */

/**
 * Implementation of hook_features_export_options. [component_hook]
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function bundle_inherit_features_export_options() {
  $inherits = bundle_inherit_load_inherits();
  $options = array();
  foreach ($inherits as $name => $inherit) {
    $options[$name] = $name;
  }

  return $options;
}

/**
 * Implementation of hook_features_export [component hook]
 *
 * @param array $data
 *   this is the machine name for the component in question
 * @param array &$export
 *   array of all components to be exported
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called
 */
function bundle_inherit_features_export($data, &$export, $module_name = '') {
  foreach ((array)$data as $name) {
    $inherit = bundle_inherit_load_inherits($name);

    if ($inherit) {
      $export['features']['bundle_inherit'][$name] = $name;
    }
  }

  return array();
}

/**
 * Implementation of hook_features_export_alter()
 *
 * Adds bundles for selected nodes that are using inheritance and dependencies if needed
 */
function bundle_inherit_features_export_alter(&$export, $module_name) {
  $inherits = bundle_inherit_load_inherits();

  foreach ($inherits as $name => $inherit) {
    if ($inherit['entity_type'] == 'node' && isset($export['features']['node'][$inherit['bundle']])) {
      $export['features']['bundle_inherit'][$name] = $name;
    }
  }

  if (!empty($export['features']['bundle_inherit'])) {
    $export['dependencies']['bundle_inherit'] = 'bundle_inherit';
    $export['dependencies']['bundle_inherit_node'] = 'bundle_inherit_node';
  }
}

/**
 * Implementation of hook_features_export_render()
 */
function bundle_inherit_features_export_render($module_name, $data) {
  $code = array();
  $code[] = '  $data = array();';
  $code[] = '';

  $inherits = bundle_inherit_load_inherits();

  foreach ($data as $name) {
    if ($inherit = bundle_inherit_load_inherits($name)) {
      $code[] = "  \$data['$name'] = " . features_var_export($inherit, '  ') . ';' . PHP_EOL;
    }
  }

  $code[] = '  return $data;';
  $code = implode("\n", $code);

  return array('bundle_inherit_defaults' => $code);
}

/**
 * Implementation of hook_features_rebuild()
 */
function bundle_inherit_features_rebuild($module) {
    bundle_inherit_features_revert($module);
}

/**
 * Implementation of hook_features_revert()
 */
function bundle_inherit_features_revert($module) {
  $data = module_invoke($module, 'bundle_inherit_defaults');

  foreach ($data as $name => $inherit) {
    // Restore the inheritance settings
    db_query("DELETE FROM {bundle_hierarchy} WHERE entity_type = :entity_type AND bundle = :bundle", array(':entity_type' => $inherit['entity_type'], ':bundle' => $inherit['entity_type']));
    db_query("INSERT INTO {bundle_hierarchy} (entity_type, bundle, bundle_parent)
              VALUES(:entity_type, :bundle, :bundle_parent)",
              array(':entity_type'    => $inherit['entity_type'],
                    ':bundle'         => $inherit['bundle'],
                    ':bundle_parent'  => $inherit['bundle_parent'],
              ));
  }
}
