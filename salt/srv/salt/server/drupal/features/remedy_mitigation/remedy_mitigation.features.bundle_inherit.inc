<?php
/**
 * @file
 * remedy_mitigation.features.bundle_inherit.inc
 */

/**
 * Implements hook_bundle_inherit_defaults().
 */
function remedy_mitigation_bundle_inherit_defaults() {
  $data = array();

  $data['configuration_task - dns_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'dns_configuration_task',
    'bundle_parent' => 'configuration_task',
  );

  $data['configuration_task - health_monitoring_config_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'health_monitoring_config_task',
    'bundle_parent' => 'configuration_task',
  );

  $data['configuration_task - relay_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'relay_configuration_task',
    'bundle_parent' => 'configuration_task',
  );

  $data['configuration_task - ssl_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'ssl_configuration_task',
    'bundle_parent' => 'configuration_task',
  );

  $data['configuration_task - vps_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'vps_configuration_task',
    'bundle_parent' => 'configuration_task',
  );

  $data['provision_vps_task - run_instance_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'run_instance_task',
    'bundle_parent' => 'provision_vps_task',
  );

  $data['provision_vps_task - terminate_instance_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'terminate_instance_task',
    'bundle_parent' => 'provision_vps_task',
  );

  $data['provisioning_task - provision_dns_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'provision_dns_task',
    'bundle_parent' => 'provisioning_task',
  );

  $data['provisioning_task - provision_ssl_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'provision_ssl_task',
    'bundle_parent' => 'provisioning_task',
  );

  $data['provisioning_task - provision_vps_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'provision_vps_task',
    'bundle_parent' => 'provisioning_task',
  );

  $data['relay_configuration_task - ip_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'ip_configuration_task',
    'bundle_parent' => 'relay_configuration_task',
  );

  $data['relay_configuration_task - virtual_host_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'virtual_host_configuration_task',
    'bundle_parent' => 'relay_configuration_task',
  );

  $data['relay_configuration_task - web_proxy_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'web_proxy_configuration_task',
    'bundle_parent' => 'relay_configuration_task',
  );

  $data['relay_configuration_task - web_server_configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'web_server_configuration_task',
    'bundle_parent' => 'relay_configuration_task',
  );

  $data['task - configuration_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'configuration_task',
    'bundle_parent' => 'task',
  );

  $data['task - credit_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'credit_task',
    'bundle_parent' => 'task',
  );

  $data['task - notification_task_'] = array(
    'entity_type' => 'node',
    'bundle' => 'notification_task_',
    'bundle_parent' => 'task',
  );

  $data['task - provisioning_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'provisioning_task',
    'bundle_parent' => 'task',
  );

  $data['task - test_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'test_task',
    'bundle_parent' => 'task',
  );

  $data['test_task - domain_testing_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'domain_testing_task',
    'bundle_parent' => 'test_task',
  );

  $data['test_task - ip_testing_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'ip_testing_task',
    'bundle_parent' => 'test_task',
  );

  $data['test_task - relay_testing_task'] = array(
    'entity_type' => 'node',
    'bundle' => 'relay_testing_task',
    'bundle_parent' => 'test_task',
  );

  return $data;
}
