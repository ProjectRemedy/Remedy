<?php
/**
 * @file
 * remedy_common.features.inc
 */

/**
 * Implements hook_default_entityform_type().
 */
function remedy_common_default_entityform_type() {
  $items = array();
  $items['prompt_input_domain_name'] = entity_import('entityform_type', '{
    "type" : "prompt_input_domain_name",
    "label" : "Provision A New Domain On A Relay",
    "weight" : "0",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : "",
      "submit_button_text" : "Provision this domain",
      "submission_rules" : { "rules_email_entityform_admin" : "rules_email_entityform_admin" },
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : "",
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "remedy\\/provision\\/domain",
      "instruction_pre" : "Please input a new domain name to provision on the relay node targeted by selected blocked domain."
    },
    "rdf_mapping" : []
  }');
  $items['prompt_input_ip_address'] = entity_import('entityform_type', '{
    "type" : "prompt_input_ip_address",
    "label" : "Provision A New IP Address",
    "weight" : "0",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : "",
      "submit_button_text" : "",
      "submission_rules" : { "rules_email_entityform_admin" : "rules_email_entityform_admin" },
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : "",
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : ""
    },
    "rdf_mapping" : []
  }');
  $items['test_ipaddress_block_mitigation'] = entity_import('entityform_type', '{
    "type" : "test_ipaddress_block_mitigation",
    "label" : "Testing IP Address Mitigation Component",
    "weight" : "0",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : "",
      "submit_button_text" : "",
      "submission_rules" : [],
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : "",
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "remedy\\/mitigation-test",
      "instruction_pre" : "Click on one of the following relay names to trigger the IP Address Blocking mitigation component."
    },
    "rdf_mapping" : []
  }');
  $items['testing_mitigation_component'] = entity_import('entityform_type', '{
    "type" : "testing_mitigation_component",
    "label" : "Testing Domain Blocking Mitigation Component",
    "weight" : "0",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : "",
      "submit_button_text" : "",
      "submission_rules" : [],
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : "",
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "remedy\\/mitigation-test",
      "instruction_pre" : "Click on one of the following domains to launch domain name blocking mitigation process. "
    },
    "rdf_mapping" : []
  }');
  $items['testing_rules_components'] = entity_import('entityform_type', '{
    "type" : "testing_rules_components",
    "label" : "Testing Rules Components",
    "weight" : "0",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : "",
      "submit_button_text" : "",
      "submission_rules" : [],
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : "",
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : ""
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function remedy_common_node_info() {
  $items = array(
    'account' => array(
      'name' => t('Account'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'action_type' => array(
      'name' => t('Action type'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'configuration_task' => array(
      'name' => t('Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'credit_task' => array(
      'name' => t('Credit Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'distribution' => array(
      'name' => t('Distribution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dns_configuration_task' => array(
      'name' => t('DNS Configuration Task'),
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
    'domain_testing_task' => array(
      'name' => t('Domain Testing Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'health_monitoring_config_task' => array(
      'name' => t('Health Monitoring Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ip_configuration_task' => array(
      'name' => t('IP Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ip_testing_task' => array(
      'name' => t('IP Testing Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'notification_task_' => array(
      'name' => t('Notification Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
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
    'provision_dns_task' => array(
      'name' => t('Provision DNS Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provision_ssl_task' => array(
      'name' => t('Provision SSL Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provision_vps_task' => array(
      'name' => t('Provision VPS Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'provisioning_task' => array(
      'name' => t('Provisioning Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'relay_configuration_task' => array(
      'name' => t('Relay Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'relay_testing_task' => array(
      'name' => t('Relay Testing Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'run_instance_task' => array(
      'name' => t('Run Instance Task'),
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
    'ssl_configuration_task' => array(
      'name' => t('SSL Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'task' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'terminate_instance_task' => array(
      'name' => t('Terminate Instance Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'test_task' => array(
      'name' => t('Test Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'virtual_host_configuration_task' => array(
      'name' => t('Virtual Host Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('VirtualHostConfigurationTask'),
      'help' => '',
    ),
    'vps_configuration_task' => array(
      'name' => t('VPS Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'web_proxy_configuration_task' => array(
      'name' => t('Web Proxy Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'web_server_configuration_task' => array(
      'name' => t('Web Server Configuration Task'),
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
 * Implements hook_workflow_features_default_workflow().
 */
function remedy_common_workflow_features_default_workflow() {
  return array(
    'Events' => array(
      'name' => 'Events',
      'tab_roles' => 'author,3',
      'options' => 'a:3:{s:16:"comment_log_node";i:0;s:15:"comment_log_tab";i:0;s:13:"name_as_title";i:0;}',
      'states' => array(
        0 => array(
          'state' => '(creation)',
          'weight' => '-50',
          'sysid' => '1',
          'status' => '1',
        ),
        1 => array(
          'state' => 'Created',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        2 => array(
          'state' => 'Confirmed',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        3 => array(
          'state' => 'Ended',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        4 => array(
          'state' => 'Invalid',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
      ),
      'transitions' => array(
        0 => array(
          'sid' => '(creation)',
          'target_sid' => 'Created',
          'roles' => 'author,3',
        ),
        1 => array(
          'sid' => '(creation)',
          'target_sid' => 'Confirmed',
          'roles' => 'author,3',
        ),
        2 => array(
          'sid' => '(creation)',
          'target_sid' => 'Ended',
          'roles' => 'author,3',
        ),
        3 => array(
          'sid' => '(creation)',
          'target_sid' => 'Invalid',
          'roles' => 'author,3',
        ),
        4 => array(
          'sid' => 'Created',
          'target_sid' => 'Confirmed',
          'roles' => 'author,3',
        ),
        5 => array(
          'sid' => 'Created',
          'target_sid' => 'Ended',
          'roles' => 'author,3',
        ),
        6 => array(
          'sid' => 'Created',
          'target_sid' => 'Invalid',
          'roles' => 'author,3',
        ),
        7 => array(
          'sid' => 'Confirmed',
          'target_sid' => 'Created',
          'roles' => 'author,3',
        ),
        8 => array(
          'sid' => 'Confirmed',
          'target_sid' => 'Ended',
          'roles' => 'author,3',
        ),
        9 => array(
          'sid' => 'Confirmed',
          'target_sid' => 'Invalid',
          'roles' => 'author,3',
        ),
        10 => array(
          'sid' => 'Ended',
          'target_sid' => 'Created',
          'roles' => 'author,3',
        ),
        11 => array(
          'sid' => 'Ended',
          'target_sid' => 'Confirmed',
          'roles' => 'author,3',
        ),
        12 => array(
          'sid' => 'Ended',
          'target_sid' => 'Invalid',
          'roles' => 'author,3',
        ),
        13 => array(
          'sid' => 'Invalid',
          'target_sid' => 'Created',
          'roles' => 'author,3',
        ),
        14 => array(
          'sid' => 'Invalid',
          'target_sid' => 'Confirmed',
          'roles' => 'author,3',
        ),
        15 => array(
          'sid' => 'Invalid',
          'target_sid' => 'Ended',
          'roles' => 'author,3',
        ),
      ),
      'node_types' => array(
        0 => array(
          'type' => 'event',
          'wid' => '3',
        ),
        1 => array(
          'type' => 'event_dns_blocked',
          'wid' => '3',
        ),
        2 => array(
          'type' => 'event_ip_blocked',
          'wid' => '3',
        ),
      ),
    ),
    'Tasks' => array(
      'name' => 'Tasks',
      'tab_roles' => '2',
      'options' => 'a:3:{s:16:"comment_log_node";i:1;s:15:"comment_log_tab";i:1;s:13:"name_as_title";i:1;}',
      'states' => array(
        0 => array(
          'state' => '(creation)',
          'weight' => '-50',
          'sysid' => '1',
          'status' => '1',
        ),
        1 => array(
          'state' => 'Created',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        2 => array(
          'state' => 'Started',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        3 => array(
          'state' => 'Running',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        4 => array(
          'state' => 'Completed',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
        5 => array(
          'state' => 'Failed',
          'weight' => '0',
          'sysid' => '0',
          'status' => '1',
        ),
      ),
      'transitions' => array(
        0 => array(
          'sid' => '(creation)',
          'target_sid' => 'Created',
          'roles' => 'author,2,3',
        ),
        1 => array(
          'sid' => '(creation)',
          'target_sid' => 'Started',
          'roles' => 'author,2',
        ),
        2 => array(
          'sid' => '(creation)',
          'target_sid' => 'Running',
          'roles' => 'author,2',
        ),
        3 => array(
          'sid' => '(creation)',
          'target_sid' => 'Completed',
          'roles' => 'author,2',
        ),
        4 => array(
          'sid' => '(creation)',
          'target_sid' => 'Failed',
          'roles' => 'author,2',
        ),
        5 => array(
          'sid' => 'Created',
          'target_sid' => 'Started',
          'roles' => 'author,2',
        ),
        6 => array(
          'sid' => 'Created',
          'target_sid' => 'Running',
          'roles' => 'author,2',
        ),
        7 => array(
          'sid' => 'Created',
          'target_sid' => 'Completed',
          'roles' => 'author,2',
        ),
        8 => array(
          'sid' => 'Created',
          'target_sid' => 'Failed',
          'roles' => 'author,2',
        ),
        9 => array(
          'sid' => 'Started',
          'target_sid' => 'Created',
          'roles' => 'author,1,2',
        ),
        10 => array(
          'sid' => 'Started',
          'target_sid' => 'Running',
          'roles' => 'author',
        ),
        11 => array(
          'sid' => 'Started',
          'target_sid' => 'Completed',
          'roles' => 'author,2',
        ),
        12 => array(
          'sid' => 'Started',
          'target_sid' => 'Failed',
          'roles' => 'author,2',
        ),
        13 => array(
          'sid' => 'Running',
          'target_sid' => 'Created',
          'roles' => 'author,2',
        ),
        14 => array(
          'sid' => 'Running',
          'target_sid' => 'Started',
          'roles' => 'author,2',
        ),
        15 => array(
          'sid' => 'Running',
          'target_sid' => 'Completed',
          'roles' => 'author,2',
        ),
        16 => array(
          'sid' => 'Running',
          'target_sid' => 'Failed',
          'roles' => 'author',
        ),
        17 => array(
          'sid' => 'Completed',
          'target_sid' => 'Created',
          'roles' => 'author,2',
        ),
        18 => array(
          'sid' => 'Completed',
          'target_sid' => 'Started',
          'roles' => 'author,2',
        ),
        19 => array(
          'sid' => 'Completed',
          'target_sid' => 'Running',
          'roles' => 'author,2',
        ),
        20 => array(
          'sid' => 'Completed',
          'target_sid' => 'Failed',
          'roles' => 'author,2',
        ),
        21 => array(
          'sid' => 'Failed',
          'target_sid' => 'Created',
          'roles' => 'author,2',
        ),
        22 => array(
          'sid' => 'Failed',
          'target_sid' => 'Started',
          'roles' => 'author,2',
        ),
        23 => array(
          'sid' => 'Failed',
          'target_sid' => 'Running',
          'roles' => 'author,2',
        ),
        24 => array(
          'sid' => 'Failed',
          'target_sid' => 'Completed',
          'roles' => 'author,2',
        ),
      ),
      'node_types' => array(
        0 => array(
          'type' => 'configuration_task',
          'wid' => '2',
        ),
        1 => array(
          'type' => 'credit_task',
          'wid' => '2',
        ),
        2 => array(
          'type' => 'dns_configuration_task',
          'wid' => '2',
        ),
        3 => array(
          'type' => 'domain_testing_task',
          'wid' => '2',
        ),
        4 => array(
          'type' => 'health_monitoring_config_task',
          'wid' => '2',
        ),
        5 => array(
          'type' => 'ip_configuration_task',
          'wid' => '2',
        ),
        6 => array(
          'type' => 'ip_testing_task',
          'wid' => '2',
        ),
        7 => array(
          'type' => 'notification_task_',
          'wid' => '2',
        ),
        8 => array(
          'type' => 'provision_dns_task',
          'wid' => '2',
        ),
        9 => array(
          'type' => 'provision_ssl_task',
          'wid' => '2',
        ),
        10 => array(
          'type' => 'provision_vps_task',
          'wid' => '2',
        ),
        11 => array(
          'type' => 'relay_configuration_task',
          'wid' => '2',
        ),
        12 => array(
          'type' => 'relay_testing_task',
          'wid' => '2',
        ),
        13 => array(
          'type' => 'run_instance_task',
          'wid' => '2',
        ),
        14 => array(
          'type' => 'ssl_configuration_task',
          'wid' => '2',
        ),
        15 => array(
          'type' => 'task',
          'wid' => '2',
        ),
        16 => array(
          'type' => 'terminate_instance_task',
          'wid' => '2',
        ),
        17 => array(
          'type' => 'test_task',
          'wid' => '2',
        ),
        18 => array(
          'type' => 'virtual_host_configuration_task',
          'wid' => '2',
        ),
        19 => array(
          'type' => 'web_proxy_configuration_task',
          'wid' => '2',
        ),
        20 => array(
          'type' => 'web_server_configuration_task',
          'wid' => '2',
        ),
      ),
    ),
  );
}
