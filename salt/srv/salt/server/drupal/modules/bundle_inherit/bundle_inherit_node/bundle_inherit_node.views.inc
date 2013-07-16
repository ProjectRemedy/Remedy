<?php
/**
 * @file
 * Provides Views with means to filter on the inherited content type.
 */

/**
 * Implements hook_views_data().
 */
function bundle_inherit_node_views_data() {
  // Give the bundle_inherit table its own group in the Views UI.
  $data['bundle_inherit']['table']['group'] = t('Bundle inherit');
  
  // Define the bundle_inherit table as a base table, that has properties of
  // its own.
  $data['bundle_inherit']['table']['base'] = array(
    'field' => 'bundle',
    'title' => t('Bundle inherit'),
    'help' => t('Contains information about field inheritance for bundles.'),
    'weight' => -10,
  );

  // Define the relationship between bundle_inherit and the node table.
  $data['bundle_inherit']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'type',
      'field' => 'bundle',
    ),
    // Make sure that we only pick up node bundles, in case there are other
    // bundles with the same name.
    'extra' => array(
      array(
        'field' => 'entity_type',
        'value' => 'node',
      ),
    ),
  );

  // Provide handlers for the bundle_inherit table.
  $data['bundle_inherit']['bundle_parent'] = array(
    'title' => t('Parent content type'),
    'help' => t('The contet type (if any) this node was inherited from.'),

    // The relationship handler is the most important one, providing data about
    // parent content type to nodes.
    'relationship' => array(
      'base' => 'bundle_inherit',
      'field' => 'bundle',
      'handler' => 'views_handler_relationship',
      'label' => t('Parent content type'),
    ),

    // The other handlers simply mimick the handlers for node types.
    'field' => array(
      'handler' => 'views_handler_field_node_type',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_node_type',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_type',
    ),
  );

  return $data;
}
