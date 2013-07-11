<?php
/**
 * @file
 * remedy_mitigation.features.inc
 */

/**
 * Implements hook_views_api().
 */
function remedy_mitigation_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function remedy_mitigation_default_entityform_type() {
  $items = array();
  $items['prompt_input_domain_name'] = entity_import('entityform_type', '{
    "type" : "prompt_input_domain_name",
    "label" : "Provision A New Domain On A Relay",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : null },
      "submit_button_text" : "Provision this domain",
      "submission_rules" : { "rules_email_entityform_admin" : "rules_email_entityform_admin" },
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : null },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "remedy\\/provision\\/domain",
      "instruction_pre" : {
        "value" : "Please input a new domain name to provision on the relay node targeted by selected blocked domain.",
        "format" : null
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/prompt-input-domain-name",
        "alias" : "remedy\\/provision\\/domain",
        "language" : "und"
      }
    }
  }');
  $items['prompt_input_ip_address'] = entity_import('entityform_type', '{
    "type" : "prompt_input_ip_address",
    "label" : "Provision A New IP Address",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : null },
      "submit_button_text" : "",
      "submission_rules" : { "rules_email_entityform_admin" : "rules_email_entityform_admin" },
      "notification_text" : "",
      "notify_emails" : "",
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : null },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : null }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/prompt-input-ip-address",
        "alias" : "remedy\\/provision\\/ipaddress",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function remedy_mitigation_node_info() {
  $items = array(
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
    'dns_configuration_task' => array(
      'name' => t('DNS Configuration Task'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'ssl_configuration_task' => array(
      'name' => t('SSL Configuration Task'),
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
 * Implements hook_workflow_default_workflows().
 */
function remedy_mitigation_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Tasks
  $workflows['Tasks'] = array(
    'name' => 'Tasks',
    'tab_roles' => 2,
    'options' => 'a:3:{s:16:"comment_log_node";i:1;s:15:"comment_log_tab";i:1;s:13:"name_as_title";i:1;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Tasks',
      ),
      1 => array(
        'state' => 'Created',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Tasks',
      ),
      2 => array(
        'state' => 'Started',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Tasks',
      ),
      3 => array(
        'state' => 'Running',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Tasks',
      ),
      4 => array(
        'state' => 'Completed',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Tasks',
      ),
      5 => array(
        'state' => 'Failed',
        'weight' => 0,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Tasks',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,authenticated user,administrator',
        'state' => '(creation)',
        'target_state' => 'Created',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => '(creation)',
        'target_state' => 'Started',
      ),
      2 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => '(creation)',
        'target_state' => 'Running',
      ),
      3 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => '(creation)',
        'target_state' => 'Completed',
      ),
      4 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => '(creation)',
        'target_state' => 'Failed',
      ),
      5 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Created',
        'target_state' => 'Started',
      ),
      6 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Created',
        'target_state' => 'Running',
      ),
      7 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Created',
        'target_state' => 'Completed',
      ),
      8 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Created',
        'target_state' => 'Failed',
      ),
      9 => array(
        'roles' => 'workflow_features_author_name,anonymous user,authenticated user',
        'state' => 'Started',
        'target_state' => 'Created',
      ),
      10 => array(
        'roles' => 'workflow_features_author_name',
        'state' => 'Started',
        'target_state' => 'Running',
      ),
      11 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Started',
        'target_state' => 'Completed',
      ),
      12 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Started',
        'target_state' => 'Failed',
      ),
      13 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Running',
        'target_state' => 'Created',
      ),
      14 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Running',
        'target_state' => 'Started',
      ),
      15 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Running',
        'target_state' => 'Completed',
      ),
      16 => array(
        'roles' => 'workflow_features_author_name',
        'state' => 'Running',
        'target_state' => 'Failed',
      ),
      17 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Completed',
        'target_state' => 'Created',
      ),
      18 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Completed',
        'target_state' => 'Started',
      ),
      19 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Completed',
        'target_state' => 'Running',
      ),
      20 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Completed',
        'target_state' => 'Failed',
      ),
      21 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Failed',
        'target_state' => 'Created',
      ),
      22 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Failed',
        'target_state' => 'Started',
      ),
      23 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Failed',
        'target_state' => 'Running',
      ),
      24 => array(
        'roles' => 'workflow_features_author_name,authenticated user',
        'state' => 'Failed',
        'target_state' => 'Completed',
      ),
    ),
    'node_types' => array(
      0 => 'configuration_task',
      1 => 'credit_task',
      2 => 'dns_configuration_task',
      3 => 'domain_testing_task',
      4 => 'health_monitoring_config_task',
      5 => 'ip_configuration_task',
      6 => 'ip_testing_task',
      7 => 'notification_task_',
      8 => 'provision_dns_task',
      9 => 'provision_ssl_task',
      10 => 'provision_vps_task',
      11 => 'relay_configuration_task',
      12 => 'relay_testing_task',
      13 => 'run_instance_task',
      14 => 'ssl_configuration_task',
      15 => 'task',
      16 => 'terminate_instance_task',
      17 => 'test_task',
      18 => 'virtual_host_configuration_task',
      19 => 'web_proxy_configuration_task',
      20 => 'web_server_configuration_task',
    ),
  );

  return $workflows;
}
