<?php
/**
 * @file
 * remedy_core.features.bundle_inherit.inc
 */

/**
 * Implements hook_bundle_inherit_defaults().
 */
function remedy_core_bundle_inherit_defaults() {
  $data = array();

  $data[' - account'] = array(
    'entity_type' => 'node',
    'bundle' => 'account',
    'bundle_parent' => '',
  );

  $data[' - domain'] = array(
    'entity_type' => 'node',
    'bundle' => 'domain',
    'bundle_parent' => '',
  );

  $data[' - event'] = array(
    'entity_type' => 'node',
    'bundle' => 'event',
    'bundle_parent' => '',
  );

  $data[' - probe'] = array(
    'entity_type' => 'node',
    'bundle' => 'probe',
    'bundle_parent' => '',
  );

  $data[' - relay'] = array(
    'entity_type' => 'node',
    'bundle' => 'relay',
    'bundle_parent' => '',
  );

  $data[' - site'] = array(
    'entity_type' => 'node',
    'bundle' => 'site',
    'bundle_parent' => '',
  );

  $data[' - tenant'] = array(
    'entity_type' => 'node',
    'bundle' => 'tenant',
    'bundle_parent' => '',
  );

  $data['event - event_dns_blocked'] = array(
    'entity_type' => 'node',
    'bundle' => 'event_dns_blocked',
    'bundle_parent' => 'event',
  );

  $data['event - event_ip_blocked'] = array(
    'entity_type' => 'node',
    'bundle' => 'event_ip_blocked',
    'bundle_parent' => 'event',
  );

  return $data;
}
