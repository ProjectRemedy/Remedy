<?php
/**
 * @file
 * remedy_core.features.inc
 */

/**
 * Implements hook_views_api().
 */
function remedy_core_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function remedy_core_node_info() {
  $items = array(
    'account' => array(
      'name' => t('Account'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'distribution' => array(
      'name' => t('Distribution Campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'domain' => array(
      'name' => t('Domain'),
      'base' => 'node_content',
      'description' => t('A given domain name, bound to one or several relays, used to access a destination web server'),
      'has_title' => '1',
      'title_label' => t('Domain Name (FQDN)'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_dns_blocked' => array(
      'name' => t('Event DNS Blocked'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_ip_blocked' => array(
      'name' => t('Event IP Blocked'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'probe' => array(
      'name' => t('Probe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'relay' => array(
      'name' => t('Relay'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A blocked destination website'),
      'has_title' => '1',
      'title_label' => t('Original Domain Name (FQDN)'),
      'help' => '',
    ),
    'tenant' => array(
      'name' => t('Tenant'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function remedy_core_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Events
  $workflows['Events'] = array(
    'name' => 'Events',
    'tab_roles' => 'author,3',
    'options' => 'a:3:{s:16:"comment_log_node";i:0;s:15:"comment_log_tab";i:0;s:13:"name_as_title";i:0;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Events',
      ),
      1 => array(
        'state' => 'Created',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Events',
      ),
      2 => array(
        'state' => 'Confirmed',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Events',
      ),
      3 => array(
        'state' => 'Ended',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Events',
      ),
      4 => array(
        'state' => 'Invalid',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Events',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => '(creation)',
        'target_state' => 'Created',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => '(creation)',
        'target_state' => 'Confirmed',
      ),
      2 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => '(creation)',
        'target_state' => 'Ended',
      ),
      3 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => '(creation)',
        'target_state' => 'Invalid',
      ),
      4 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Created',
        'target_state' => 'Confirmed',
      ),
      5 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Created',
        'target_state' => 'Ended',
      ),
      6 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Created',
        'target_state' => 'Invalid',
      ),
      7 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Confirmed',
        'target_state' => 'Created',
      ),
      8 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Confirmed',
        'target_state' => 'Ended',
      ),
      9 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Confirmed',
        'target_state' => 'Invalid',
      ),
      10 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Ended',
        'target_state' => 'Created',
      ),
      11 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Ended',
        'target_state' => 'Confirmed',
      ),
      12 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Ended',
        'target_state' => 'Invalid',
      ),
      13 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Invalid',
        'target_state' => 'Created',
      ),
      14 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Invalid',
        'target_state' => 'Confirmed',
      ),
      15 => array(
        'roles' => 'workflow_features_author_name,administrator',
        'state' => 'Invalid',
        'target_state' => 'Ended',
      ),
    ),
    'node_types' => array(
      0 => 'event',
      1 => 'event_dns_blocked',
      2 => 'event_ip_blocked',
    ),
  );

  return $workflows;
}
