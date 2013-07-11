<?php
/**
 * @file
 * remedy_mitigation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function remedy_mitigation_default_rules_configuration() {
  $items = array();
  $items['rules_assign_a_new_ip_address_to_a_node'] = entity_import('rules_config', '{ "rules_assign_a_new_ip_address_to_a_node" : {
      "LABEL" : "Assign a new IP address to a node",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update", "cron" ],
      "DO" : []
    }
  }');
  $items['rules_check_blocked_domain_event_node'] = entity_import('rules_config', '{ "rules_check_blocked_domain_event_node" : {
      "LABEL" : "Check Blocked Domain Event Node",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : { "blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" } },
      "AND" : [
        { "php_eval" : { "code" : "\\/*\\r\\n$target_query = new EntityFieldQuery();\\r\\n$target_query-\\u003EentityCondition(\\u0022entity_type\\u0022, \\u0022node\\u0022)\\r\\n        -\\u003EentityCondition(\\u0022bundle\\u0022, \\u0022event_dns_blocked\\u0022)\\r\\n        -\\u003EpropertyCondition(\\u0022status\\u0022, 1)\\r\\n        -\\u003EfieldCondition(\\u0022field_target\\u0022, \\u0022target_id\\u0022, $blocked_domain_nid);\\r\\n\\r\\n$result = $target_query-\\u003Eexecute();\\r\\nforeach($result[\\u0027node\\u0027] as $key =\\u003E $val) {\\r\\n    $node = node_load($val-\\u003Enid);\\r\\n    if($node-\\u003Eworkflow == 13 || $node-\\u003Eworkflow == 14 || $node-\\u003Eworkflow == 15) { return false; }\\r\\n}\\r\\n*\\/\\r\\nreturn true;" } }
      ]
    }
  }');
  $items['rules_check_blocked_ip_addressevent_node'] = entity_import('rules_config', '{ "rules_check_blocked_ip_addressevent_node" : {
      "LABEL" : "Check Blocked IP AddressEvent Node",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : { "blocked_relay_nid" : { "label" : "Blocked Relay Nid", "type" : "integer" } },
      "AND" : [
        { "php_eval" : { "code" : "dsm($blocked_relay_nid);\\r\\n$target_query = new EntityFieldQuery();\\r\\n$target_query-\\u003EentityCondition(\\u0022entity_type\\u0022, \\u0022node\\u0022)\\r\\n        -\\u003EentityCondition(\\u0022bundle\\u0022, \\u0022event_ip_blocked\\u0022)\\r\\n        -\\u003EpropertyCondition(\\u0022status\\u0022, 1)\\r\\n        -\\u003EfieldCondition(\\u0022field_target\\u0022, \\u0022target_id\\u0022, $blocked_relay_nid);\\r\\n\\r\\n$result = $target_query-\\u003Eexecute();\\r\\n\\r\\nif (isset($result[\\u0027node\\u0027])) {\\r\\nforeach($result[\\u0027node\\u0027] as $key =\\u003E $val) {\\r\\n    $node = node_load($val-\\u003Enid);\\r\\n    if($node-\\u003Eworkflow == 13 || $node-\\u003Eworkflow == 14 || $node-\\u003Eworkflow == 15) { return false; }\\r\\n}\\r\\n}\\r\\nreturn true;" } }
      ]
    }
  }');
  $items['rules_checkavailability_new_ip'] = entity_import('rules_config', '{ "rules_checkavailability_new_ip" : {
      "LABEL" : "CheckAvailability New IP",
      "PLUGIN" : "and",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : { "ip_address" : { "label" : "IP Address", "type" : "text" } },
      "AND" : [
        { "php_eval" : { "code" : "\\/\\/XML-RPC Call for controller.test_asset(\\u0022ip_block\\u0022, \\u0022199.59.150.39\\u0022)" } }
      ]
    }
  }');
  $items['rules_configure_manual_healthmonitor'] = entity_import('rules_config', '{ "rules_configure_manual_healthmonitor" : {
      "LABEL" : "Configure Manual HealthMonitor",
      "PLUGIN" : "rule",
      "DO" : []
    }
  }');
  $items['rules_configure_manual_ssl_certificate'] = entity_import('rules_config', '{ "rules_configure_manual_ssl_certificate" : {
      "LABEL" : "Configure Manual SSL Certificate",
      "PLUGIN" : "rule",
      "DO" : []
    }
  }');
  $items['rules_configure_manual_virtualhost'] = entity_import('rules_config', '{ "rules_configure_manual_virtualhost" : {
      "LABEL" : "Configure Manual VirtualHost",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "mimemail" ],
      "USES VARIABLES" : {
        "blocked_domain" : { "label" : "Blocked Domain", "type" : "node" },
        "new_domain" : { "label" : "New Domain", "type" : "text" },
        "blocked_domain_event" : { "label" : "Event", "type" : "node" }
      },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "virtual_host_configuration_task",
              "param_title" : "Virtual Host Configuration for [new-domain]",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "virtual_host_configuration_task" : "Virtual Host Configuration Task" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "ssh rp_ec2_instance \\u0022sed \\u0027s\\/[blocked-domain:title]\\/[new-domain]\\/g\\u0027 \\/path\\/to\\/nginx.conf \\u003E \\/path\\/to\\/nginx.conf.new"
            },
            "PROVIDE" : { "variable_added" : { "new_domain_vhost_bash" : "new_domain_vhost_bash" } }
          }
        },
        { "mimemail" : {
            "to" : [ "site:current-user:mail" ],
            "subject" : "Webserver configuration for new domain \\u003C?php echo $new_domain; ?\\u003E",
            "body" : "Hi [site:current-user-name],\\u003Cbr\\u003E\\r\\nThe blocking on domain \\u003C?php echo $blocked_domain-\\u003Etitle; ?\\u003E has been mitigated by a new domain : \\u003C?php echo $new_domain; ?\\u003E. \\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\nHere is the command to paste into your CLI to configure your webserver.\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003C?php echo $new_domain_vhost_bash\\t; ?\\u003E\\r\\n\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\nBest regards,\\u003Cbr \\/\\u003E\\r\\nRemedy Admin Team"
          }
        },
        { "drupal_message" : { "message" : "You have received instructions by email to setup virtual host on new domain [new-domain]." } },
        { "data_set" : {
            "data" : [ "virtual-host-configuration-task:field-dns-blocking-event" ],
            "value" : [ "blocked-domain-event" ]
          }
        },
        { "data_set" : {
            "data" : [ "virtual-host-configuration-task:field-data" ],
            "value" : "[new-domain-vhost-bash]"
          }
        },
        { "entity_save" : { "data" : [ "virtual-host-configuration-task" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_configuring_new_dns'] = entity_import('rules_config', '{ "rules_configuring_new_dns" : {
      "LABEL" : "COnfiguring new DNS",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_transition" : {
            "node" : [ "node" ],
            "old_state" : { "value" : { "5" : "5" } },
            "new_state" : { "value" : { "4" : "4" } }
          }
        },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "DNSSimple API based DNS Server configuration (by default bind new domain to all IPs from all relays) -\\u003E If SSL : Bind new SSL 5. -\\u003E Bind Node 6." } },
        { "drupal_message" : { "message" : "Install SSL certificate on RelayNodes.VirtualHost (Send config steps to RemedyAdmin 9.)" } },
        { "drupal_message" : { "message" : "Add new Domain name to Health Monitoring Infra (Sending an alert to RemedyAdmin 9.)" } },
        { "workflow_rules_set_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ]
    }
  }');
  $items['rules_deprovision_dns_health_monitoring'] = entity_import('rules_config', '{ "rules_deprovision_dns_health_monitoring" : {
      "LABEL" : "Deprovision DNS Health Monitoring",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "provision_domain" : { "label" : "Domain Name", "type" : "text" },
        "probe_ipaddress" : { "label" : "Probe IP address", "type" : "text" }
      },
      "DO" : [
        { "drupal_message" : { "message" : "Deprovisionning DNS Health Monitoring for \\u003C?php echo $provision_domain; ?\\u003E on probe \\u003C?php echo $probe_ipaddress; ?\\u003E" } },
        { "php_eval" : { "code" : "\\/\\/Deprovision DNS Health Monitoring\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe_ipaddress, array(\\u0022operate_asset\\u0022 =\\u003E array(\\u0022delete_asset\\u0022, \\u0022domain\\u0022, $provision_domain)));" } }
      ]
    }
  }');
  $items['rules_deprovision_ip_address_health_monitoring'] = entity_import('rules_config', '{ "rules_deprovision_ip_address_health_monitoring" : {
      "LABEL" : "Deprovision IP Address Health Monitoring",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "provision_ip_address" : { "label" : "IP address", "type" : "text" },
        "probe_ipaddress" : { "label" : "Probe IP address", "type" : "text" }
      },
      "DO" : [
        { "drupal_message" : { "message" : "Deprovisionning IP Address Health Monitoring for \\u003C?php echo $provision_ip_address; ?\\u003E on probe \\u003C?php echo $probe_ipaddress; ?\\u003E" } },
        { "php_eval" : { "code" : "\\/\\/Delete IP Address From Health Monitoring\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe_ipaddress, array(\\u0022operate_asset\\u0022 =\\u003E array(\\u0022delete_asset\\u0022, \\u0022ip\\u0022, $provision_ip_address)));" } }
      ]
    }
  }');
  $items['rules_dns_mitigation_marked_as_unsuccessful'] = entity_import('rules_config', '{ "rules_dns_mitigation_marked_as_unsuccessful" : {
      "LABEL" : "DNS Mitigation : Marked As Unsuccessful",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "USES VARIABLES" : {
        "new_domain_node" : { "label" : "New Domain Node", "type" : "node" },
        "event_node" : { "label" : "Event Node", "type" : "node" }
      },
      "IF" : [
        { "component_rules_test_domain" : {
            "domain_to_test" : "[new-domain-node:title]",
            "probe" : "[new-domain-node:title]"
          }
        },
        { "entity_has_field" : { "entity" : [ "event-node" ], "field" : "field_target" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_dns_blocking_event",
              "value" : [ "event-node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "linked_dns_tasks" : "Linked Tasks" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "linked-dns-tasks" ] },
            "ITEM" : { "list_task" : "Current task" },
            "DO" : [
              { "workflow_rules_set_state" : {
                  "node" : [ "list-task" ],
                  "workflow_state" : { "value" : { "12" : "12" } }
                }
              }
            ]
          }
        },
        { "workflow_rules_set_state" : {
            "node" : [ "event-node" ],
            "workflow_state" : { "value" : { "15" : "15" } }
          }
        }
      ]
    }
  }');
  $items['rules_dns_mitigation_successful'] = entity_import('rules_config', '{ "rules_dns_mitigation_successful" : {
      "LABEL" : "DNS Mitigation : Marked As Successful",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "USES VARIABLES" : {
        "new_domain_node" : { "label" : "New Domain Node", "type" : "node" },
        "event_node" : { "label" : "Event Node", "type" : "node" }
      },
      "IF" : [
        { "NOT component_rules_test_domain" : {
            "domain_to_test" : "[new-domain-node:title]",
            "probe" : "[new-domain-node:title]"
          }
        },
        { "entity_has_field" : { "entity" : [ "event-node" ], "field" : "field_target" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_dns_blocking_event",
              "value" : [ "event-node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "linked_dns_tasks" : "Linked Tasks" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "linked-dns-tasks" ] },
            "ITEM" : { "list_task" : "Current task" },
            "DO" : [
              { "workflow_rules_set_state" : {
                  "node" : [ "list-task" ],
                  "workflow_state" : { "value" : { "17" : "17" } }
                }
              },
              { "entity_save" : { "data" : [ "list-task" ], "immediate" : 1 } }
            ]
          }
        },
        { "workflow_rules_set_state" : {
            "node" : [ "event-node" ],
            "workflow_state" : { "value" : { "16" : "16" } }
          }
        }
      ]
    }
  }');
  $items['rules_dns_simple_api_trigger'] = entity_import('rules_config', '{ "rules_dns_simple_api_trigger" : {
      "LABEL" : "Provisionning new domains\\/SSL",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "dns_blocking" ],
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Buying domain on DNS Simple (or assigning already provisionned domains)" } },
        { "drupal_message" : { "message" : "DNS Simple API based SSL certificate purchase" } },
        { "workflow_rules_set_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  $items['rules_initiate_domain_blocking_event'] = entity_import('rules_config', '{ "rules_initiate_domain_blocking_event" : {
      "LABEL" : "Initiate Domain Blocking Event",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "workflow_rules" ],
      "USES VARIABLES" : {
        "event_blocked_domain" : { "label" : "Blocked Domain", "type" : "text" },
        "event_check_data" : { "label" : "Data", "type" : "text" },
        "event_blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" }
      },
      "IF" : [
        { "component_rules_check_blocked_domain_event_node" : { "blocked_domain_nid" : [ "event-blocked-domain-nid" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "event_dns_blocked",
              "param_title" : "Blocking Event on Domain : \\u003C?php echo $event_blocked_domain; ?\\u003E on \\u003C?php echo date(\\u0022Y-m-d H:i:s\\u0022, time()); ?\\u003E",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "blocking_event_node" : "Blocking Event Node" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "event-blocked-domain-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_node" : "Blocked Domain Node" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_target_domain",
              "value" : [ "event-blocked-domain-nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_distribution_campaign" : "Blocked Domain Distribution Campaign" } }
          }
        },
        { "php_eval" : { "code" : "$blocking_event_node\\t-\\u003Efield_target[\\u0027und\\u0027][][\\u0027target_id\\u0027] = $blocked_domain_node-\\u003Enid;" } },
        { "entity_save" : { "data" : [ "blocking-event-node" ], "immediate" : 1 } },
        { "workflow_rules_set_state" : {
            "node" : [ "blocking-event-node" ],
            "workflow_state" : { "value" : { "15" : "15" } }
          }
        },
        { "component_rules_notify_event_domain_blocking" : {
            "event_blocked_domain" : "\\u003C?php echo $event_blocked_domain; ?\\u003E",
            "event_blocked_data" : "\\u003C?php echo $event_check_data; ?\\u003E",
            "event_blocked_domain_nid" : [ "event_blocked_domain_nid" ],
            "event_blocked_event_nid" : [ "blocking-event-node:nid" ]
          }
        },
        { "redirect" : { "url" : "dashboard" } }
      ]
    }
  }');
  $items['rules_initiate_ipaddress_blocking_event'] = entity_import('rules_config', '{ "rules_initiate_ipaddress_blocking_event" : {
      "LABEL" : "Initiate IP Address Blocking Event",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "workflow_rules" ],
      "USES VARIABLES" : {
        "blocked_data" : { "label" : "Data", "type" : "text" },
        "blocked_relay_node" : { "label" : "Blocked Relay Node", "type" : "node" }
      },
      "IF" : [
        { "component_rules_test_ipaddress" : {
            "ip_address_to_test" : "[blocked-relay-node:field-ip-address]",
            "probe" : "probe1"
          }
        },
        { "component_rules_check_blocked_ip_addressevent_node" : { "blocked_relay_nid" : [ "blocked-relay-node:nid" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "event_ip_blocked",
              "param_title" : "Blocking Event on IP Address : [blocked-relay-node:field-ip-address] on \\u003C?php echo date(\\u0022Y-m-d h:i:s\\u0022);",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "blocked_relay_event_node" : "IP Address Blocked Event" } }
          }
        },
        { "entity_save" : { "data" : [ "blocked-relay-event-node" ], "immediate" : 1 } },
        { "workflow_rules_set_state" : {
            "node" : [ "blocked-relay-event-node" ],
            "workflow_state" : { "value" : { "15" : "15" } }
          }
        },
        { "data_set" : {
            "data" : [ "blocked-relay-event-node:field-target" ],
            "value" : [ "blocked-relay-node" ]
          }
        },
        { "entity_save" : { "data" : [ "blocked-relay-event-node" ], "immediate" : 1 } },
        { "component_rules_notify_event_ipaddress_blocking" : {
            "blocked_data" : "Test",
            "blocked_relay_node" : [ "blocked_relay_node" ],
            "blocked_relay_event_node" : [ "blocked_relay_event_node" ]
          }
        },
        { "redirect" : { "url" : "dashboard" } }
      ]
    }
  }');
  $items['rules_ip_address_mitigation_marked_as_successful'] = entity_import('rules_config', '{ "rules_ip_address_mitigation_marked_as_successful" : {
      "LABEL" : "IP Address Mitigation : Marked As Successful",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "USES VARIABLES" : {
        "relay_node" : { "label" : "Relay Node", "type" : "node" },
        "event_node" : { "label" : "Event Node", "type" : "node" }
      },
      "IF" : [
        { "NOT component_rules_test_domain" : {
            "domain_to_test" : "[relay-node:field-ip-address]\\t",
            "probe" : "[new-domain-node:title]"
          }
        },
        { "entity_has_field" : { "entity" : [ "event-node" ], "field" : "field_target" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_ip_address_blocking_event",
              "value" : [ "event-node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "linked_ip_address_tasks" : "Linked Tasks" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "linked-ip-address-tasks" ] },
            "ITEM" : { "list_task" : "Current task" },
            "DO" : [
              { "workflow_rules_set_state" : {
                  "node" : [ "list-task" ],
                  "workflow_state" : { "value" : { "11" : "11" } }
                }
              }
            ]
          }
        },
        { "workflow_rules_set_state" : {
            "node" : [ "event-node" ],
            "workflow_state" : { "value" : { "15" : "15" } }
          }
        }
      ]
    }
  }');
  $items['rules_ip_address_mitigation_marked_as_unsuccessful'] = entity_import('rules_config', '{ "rules_ip_address_mitigation_marked_as_unsuccessful" : {
      "LABEL" : "IP Address Mitigation : Marked As Unsuccessful",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "workflow_rules", "devel" ],
      "USES VARIABLES" : {
        "relay_node" : { "label" : "Relay Node", "type" : "node" },
        "event_node" : { "label" : "Event Node", "type" : "node" }
      },
      "IF" : [
        { "component_rules_test_domain" : {
            "domain_to_test" : "[relay-node:field-ip-address]\\t",
            "probe" : "[new-domain-node:title]"
          }
        },
        { "entity_has_field" : { "entity" : [ "event-node" ], "field" : "field_target" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_ip_address_blocking_event",
              "value" : [ "event-node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "linked_ip_address_tasks" : "Linked Tasks" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "linked-ip-address-tasks" ] },
            "ITEM" : { "list_task" : "Current task" },
            "DO" : [
              { "workflow_rules_set_state" : {
                  "node" : [ "list-task" ],
                  "workflow_state" : { "value" : { "12" : "12" } }
                }
              },
              { "devel_debug" : { "value" : [ "list-task" ] } }
            ]
          }
        },
        { "workflow_rules_set_state" : {
            "node" : [ "event-node" ],
            "workflow_state" : { "value" : { "15" : "15" } }
          }
        },
        { "devel_debug" : { "value" : [ "event-node" ] } }
      ]
    }
  }');
  $items['rules_ip_configuration_task'] = entity_import('rules_config', '{ "rules_ip_configuration_task" : {
      "LABEL" : "Populate IP Address Configuration Task ",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "provision_relay_node" : { "label" : "Relay Node", "type" : "node" },
        "provision_event_node" : { "label" : "Event Node", "type" : "node" },
        "provision_task_node" : { "label" : "Task Node", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "provision-event-node" ], "field" : "field_target" } },
        { "entity_has_field" : {
            "entity" : [ "provision-task-node" ],
            "field" : "field_ip_address_blocking_event"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "provision-task-node:field-ip-address-blocking-event" ],
            "value" : [ "provision-event-node" ]
          }
        },
        { "entity_save" : { "data" : [ "provision-task-node" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_ip_mitigation_validation_check'] = entity_import('rules_config', '{ "rules_ip_mitigation_validation_check" : {
      "LABEL" : "IP Mitigation Validation Check",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "checked_relay" : { "label" : "Checked Relay", "type" : "node" },
        "checked_event" : { "label" : "Checked Event", "type" : "node" },
        "probe_ipaddress" : { "label" : "Probe IP address", "type" : "text" }
      },
      "AND" : [
        { "php_eval" : { "code" : "\\/\\/Delete IP Address From Health Monitoring\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe_ipaddress, array(\\u0022test_asset\\u0022 =\\u003E array(\\u0022ip_injection\\u0022, \\u0022[checked-relay:field-ip-address]\\u0022)));" } }
      ]
    }
  }');
  $items['rules_link_set_describe_instance_ec2'] = entity_import('rules_config', '{ "rules_link_set_describe_instance_ec2" : {
      "LABEL" : "Rules link: Describe Instance EC2 rules set",
      "PLUGIN" : "rule set",
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : []
    }
  }');
  $items['rules_link_set_mitigate_dns_blocking_test'] = entity_import('rules_config', '{ "rules_link_set_mitigate_dns_blocking_test" : {
      "LABEL" : "Rules link: Mitigate DNS Blocking Test rules set",
      "PLUGIN" : "rule set",
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : []
    }
  }');
  $items['rules_link_set_test_aws_ec2'] = entity_import('rules_config', '{ "rules_link_set_test_aws_ec2" : {
      "LABEL" : "Rules link: Test AWS EC2 rules set",
      "PLUGIN" : "rule set",
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : []
    }
  }');
  $items['rules_mitigation_sequence_exec_dns_blocking_as'] = entity_import('rules_config', '{ "rules_mitigation_sequence_exec_dns_blocking_as" : {
      "LABEL" : "Mitigation Sequence - Exec : DNS Blocking",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules", "php", "workflow_rules" ],
      "USES VARIABLES" : {
        "domain" : { "label" : "Domain", "type" : "text" },
        "blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" },
        "blocked_domain_event_nid" : { "label" : "Blocked Domain Event Nid", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "blocked-domain-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_node" : "Blocked Domain Node" } }
          }
        },
        { "component_rules_provision_dns" : {
            "provision_domain" : "\\u003C?php echo $domain; ?\\u003E",
            "provision_blocked_domain_nid" : [ "blocked-domain-nid" ],
            "blocked_domain_event_nid" : [ "blocked_domain_event_nid" ]
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "blocked-domain-event-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_event_node" : "Blocked Domain Event Node" } }
          }
        },
        { "component_rules_configure_manual_virtualhost" : {
            "blocked_domain" : [ "blocked-domain-node" ],
            "new_domain" : "[domain]",
            "blocked_domain_event" : [ "blocked-domain-event-node" ]
          }
        },
        { "component_rules_configure_manual_ssl_certificate" : [] },
        { "component_rules_configure_manual_healthmonitor" : [] },
        { "workflow_rules_set_state" : {
            "node" : [ "blocked-domain-event-node" ],
            "workflow_state" : { "value" : { "16" : "16" } }
          }
        },
        { "redirect" : { "url" : "node\\/[blocked-domain-event-nid]\\t" } }
      ]
    }
  }');
  $items['rules_mitigation_sequence_exec_ipaddress_blockin'] = entity_import('rules_config', '{ "rules_mitigation_sequence_exec_ipaddress_blockin" : {
      "LABEL" : "Mitigation Sequence - Exec : IP Address Blocking",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "USES VARIABLES" : {
        "blocked_relay" : { "label" : "Blocked Relay", "type" : "node" },
        "blocked_relay_event" : { "label" : "Blocked Relay Event", "type" : "node" }
      },
      "ACTION SET" : [
        { "component_rules_provision_ipaddress" : [] },
        { "component_rules_configure_manual_healthmonitor" : [] },
        { "workflow_rules_set_state" : {
            "node" : [ "blocked-relay-event" ],
            "workflow_state" : { "value" : { "16" : "16" } }
          }
        },
        { "redirect" : { "url" : [ "blocked-relay-event:url" ] } }
      ]
    }
  }');
  $items['rules_mitigation_sequence_init_dns_blocking'] = entity_import('rules_config', '{ "rules_mitigation_sequence_init_dns_blocking" : {
      "LABEL" : "Mitigation Sequence - Init : DNS Blocking",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "blocked_domain" : { "label" : "Blocked Domain", "type" : "text" },
        "check_data" : { "label" : "Data", "type" : "text" },
        "blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" }
      },
      "ACTION SET" : [
        { "component_rules_initiate_domain_blocking_event" : {
            "event_blocked_domain" : "\\u003C?php echo $blocked_domain; ?\\u003E",
            "event_check_data" : "\\u003C?php echo $check_data; ?\\u003E",
            "event_blocked_domain_nid" : [ "blocked-domain-nid" ]
          }
        }
      ]
    }
  }');
  $items['rules_mitigation_sequence_init_ipaddress_blocking'] = entity_import('rules_config', '{ "rules_mitigation_sequence_init_ipaddress_blocking" : {
      "LABEL" : "Mitigation Sequence - Init : IP Address Blocking",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "blocked_relay_node" : { "label" : "Blocked Relay Node", "type" : "node" },
        "check_data" : { "label" : "Data", "type" : "text" }
      },
      "ACTION SET" : [
        { "component_rules_initiate_ipaddress_blocking_event" : {
            "blocked_data" : "Test",
            "blocked_relay_node" : [ "blocked_relay_node" ]
          }
        }
      ]
    }
  }');
  $items['rules_monitor_dns'] = entity_import('rules_config', '{ "rules_monitor_dns" : {
      "LABEL" : "Monitor Domain Name",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : [ "entityform_insert" ],
      "IF" : [
        { "NOT entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_blocking_event" } },
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_testing_domain" } }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_init_dns_blocking" : {
            "blocked_domain" : "[entityform:field-testing-domain]",
            "check_data" : "[Health Monitoring Output]",
            "blocked_domain_nid" : [ "entityform:field-testing-domain:nid" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify'] = entity_import('rules_config', '{ "rules_notify" : {
      "LABEL" : "Notify",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "php", "rules" ],
      "ON" : [ "cron" ],
      "IF" : [
        { "php_eval" : { "code" : "$relay = node_load($row-\\u003Efield_host);\\r\\n$ip = \\u0022208.113.146.107\\u0022;\\r\\n\\/\\/$ip = $relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027safe_value\\u0027];\\r\\n\\/\\/Iterate over various probes to see if the IP matches.\\r\\n$rrd_file = \\u0022\\/opt\\/collectd\\/var\\/lib\\/collectd\\/rrd\\/remedy-prober-cn1\\/website.info\\/IPBlock-\\u0022 . $ip . \\u0022.rrd\\u0022;\\r\\n\\/\\/$options = array(\\u0022AVERAGE\\u0022, \\u0022--start\\u0022, \\u0022-1h\\u0022);\\r\\n\\/\\/$data_rrd = rrd_fetch($rrd_file, $options, count($options));\\r\\n$data_rrd = rrd_lastupdate($rrd_file);\\r\\n$ret = $data_rrd[\\u0027data\\u0027][0];\\r\\n\\/\\/$ret = $data_rrd[\\u0027data\\u0027][12];\\r\\n\\/\\/$ret = \\u0022\\u003Cbr\\/\\u003E\\u0022 . dprint_r($data_rrd,true);\\r\\nreturn $ret==\\u00221\\u0022;" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "jmatsushita@internews.eu",
            "subject" : "Remedy Notification",
            "message" : "Alert!",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_event_domain_blocking'] = entity_import('rules_config', '{ "rules_notify_event_domain_blocking" : {
      "LABEL" : "Notify Event Domain Blocking",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "mimemail" ],
      "USES VARIABLES" : {
        "event_blocked_domain" : { "label" : "Domain", "type" : "text" },
        "event_blocked_data" : { "label" : "Data", "type" : "text" },
        "event_blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" },
        "event_blocked_event_nid" : { "label" : "Blocked Domain Event Nid", "type" : "integer" }
      },
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_target_domain",
              "value" : [ "event-blocked-domain-nid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_distribution_campaign_node" : "Blocked Domain Distribution Campaign Node" } }
          }
        },
        { "mimemail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "[Remedy] Blocked Domain : \\u003C?php echo $event_blocked_domain; ?\\u003E",
            "body" : "Hi relay admin,\\u003Cbr \\/\\u003E\\r\\nThe following domain has been reported as blocked since 3 hours : \\u003Cbr \\/\\u003E\\r\\n\\u003Cli\\u003EDomain : \\u003C?php echo $event_blocked_domain; ?\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C?php \\r\\nif(count($blocked_domain_distribution_campaign_node) \\u003E 0) {\\r\\n?\\u003E\\r\\n\\u003Cli\\u003EDomain Distribution Campaign : \\u003C?php echo $blocked_domain_distribution_campaign_node[0]-\\u003Etitle; ?\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C?php\\r\\n}\\r\\n?\\u003E\\r\\n\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\nYou can launch the mitigation process by clicking on the following link : \\u003Ca href=\\u0022[site:url]remedy\\/provision\\/domain?edit[field_blocked_domain][und]=\\u003C?php echo $event_blocked_domain_nid; ?\\u003E\\u0026edit[field_blocking_event][und]=\\u003C?php echo $event_blocked_event_nid; ?\\u003E\\u0022\\u003E[site:url]remedy\\/provision\\/domain?edit[field_blocked_domain][und]=\\u003C?php echo $event_blocked_domain_nid; ?\\u003E\\u0026edit[field_blocking_event][und]=\\u003C?php echo $event_blocked_event_nid; ?\\u003E\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Cbr \\/\\u003E\\r\\nBest regards,\\u003Cbr \\/\\u003E\\r\\nRemedy Admin Team",
            "plaintext" : "Hi relay admin,\\r\\nThe following domain has been reported as blocked since 3 hours : \\r\\nDomain : \\u003C?php echo $event_blocked_domain;?\\u003E\\r\\n\\u003C?php \\r\\nif(count($blocked_domain_distribution_campaign_node) \\u003E 0){\\r\\n?\\u003E\\r\\n\\u003Cli\\u003EDomain Distribution Campaign : \\u003C?php echo $blocked_domain_distribution_campaign_node[0]-\\u003Etitle; ?\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C?php\\r\\n}\\r\\n?\\u003E\\r\\nYou can launch the mitigation process by clicking on the following link : \\r\\n[site:url]remedy\\/provision\\/domain?edit[field_blocked_domain][und]=\\u003C?php echo $event_blocked_domain_nid; ?\\u003E\\u0026edit[field_blocking_event][und]=\\u003C?php echo $event_blocked_event_nid; ?\\u003E\\r\\n\\r\\nBest regards,\\r\\nRemedy Admin Team"
          }
        },
        { "drupal_message" : {
            "message" : "The domain has been reported as blocked : \\u003C?php echo $event_blocked_domain;?\\u003E. You can launch the mitigation process by clicking on the following link : \\u003Ca href=\\u0022[site:url]remedy\\/provision\\/domain?edit[field_blocked_domain][und]=\\u003C?php echo $event_blocked_domain_nid; ?\\u003E\\u0026edit[field_blocking_event][und]=\\u003C?php echo $event_blocked_event_nid; ?\\u003E\\u0022\\u003E[site:url]remedy\\/provision\\/domain?edit[field_blocked_domain][und]=\\u003C?php echo $event_blocked_domain_nid; ?\\u003E\\u0026edit[field_blocking_event][und]=\\u003C?php echo $event_blocked_event_nid; ?\\u003E\\u003C\\/a\\u003E.",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  $items['rules_notify_event_ipaddress_blocking'] = entity_import('rules_config', '{ "rules_notify_event_ipaddress_blocking" : {
      "LABEL" : "Notify Event IP Address Blocking",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "mimemail" ],
      "USES VARIABLES" : {
        "blocked_data" : { "label" : "Data", "type" : "text" },
        "blocked_relay_node" : { "label" : "Blocked Relay Node", "type" : "node" },
        "blocked_relay_event_node" : { "label" : "Blocked Relay Event Node", "type" : "node" }
      },
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_domain_relays",
              "value" : [ "blocked-relay-node:nid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "blocked_relay_domains" : "Blocked Relay Domains" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_target_domain",
              "value" : [ "blocked-relay-domains:0:nid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_distribution_campaign_node" : "Blocked Domain Distribution Campaign Node" } }
          }
        },
        { "drupal_message" : {
            "message" : "Hi Remedy Admin. A IP address has been blocked on relay : [blocked-relay-node:title]. You have received mitigation instructions by email.",
            "type" : "warning"
          }
        },
        { "mimemail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "[Remedy] Blocked IP Address\\r\\n",
            "body" : "Hello, \\u003Cbr \\/\\u003E\\r\\nThe following IP Address has been reported as blocked since 3 hours : \\u003Cbr \\/\\u003E\\r\\n\\u003Cli\\u003ERelay Name : [blocked-relay-node:title]\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EIP : [blocked-relay-node:field-ip-address]\\u003C\\/li\\u003E\\r\\n\\u003C?php if(count($blocked_relay_domains) \\u003E 0) { ?\\u003E\\r\\n\\u003Cli\\u003EDomain Name : \\u003C?php echo $blocked_relay_domains[0]-\\u003Etitle; ?\\u003E\\u003C\\/li\\u003E\\r\\n\\u003C?php if(count($blocked_domain_distribution_campaign_node) \\u003E 0) { ?\\u003E\\r\\n\\u003Cli\\u003EDistribution Campaign : \\u003C?php echo $blocked_domain_distribution_campaign_node[0]-\\u003Etitle; ?\\u003E\\r\\n\\u003C?php } } ?\\u003E\\r\\n\\u003Cbr \\/\\u003E\\u003Cbr \\/\\u003E\\r\\nYou can launch the mitigation process by clicking on the following link : \\u003Ca href=\\u0022[site:url]remedy\\/provision\\/ipaddress?edit[field_relays][und]=[blocked-relay-node:nid]\\u0026edit[field_ip_address_blocking_event][und]=[blocked-relay-event-node:nid]\\u0022\\u003E[site:url]remedy\\/provision\\/ipaddress?edit[field_relays][und]=[blocked-relay-node:nid]\\u0026edit[field_ip_address_blocking_event][und]=[blocked-relay-event-node:nid]\\u003C\\/a\\u003E\\u003Cbr \\/\\u003E\\r\\n\\u003Cbr \\/\\u003E\\r\\nBest regards,\\u003Cbr \\/\\u003E\\r\\nRemedy Admin Team",
            "plaintext" : "Hello\\r\\n\\r\\nThe following IP Address has been reported as blocked : \\r\\nRelay Name : [blocked-relay-node:title]\\r\\nIP : [blocked-relay-node:field-ip-address]\\r\\n\\u003C?php if(count($blocked_relay_domains) \\u003E 0) { ?\\u003E\\r\\nDomain Name : \\u003C?php echo $blocked_relay_domains[0]-\\u003Etitle; ?\\u003E\\r\\n\\r\\n\\u003C?php if(count($blocked_domain_distribution_campaign_node) \\u003E 0) { ?\\u003E\\r\\nDistribution Campaign : \\u003C?php echo $blocked-domain-distribution-campaign-node[0]-\\u003Etitle; ?\\u003E\\r\\n\\u003C?php } } ?\\u003E\\r\\n\\r\\nYou can launch the mitigation process by clicking on the following link : \\r\\n[site:url]remedy\\/provision\\/ipaddress?edit[field_relays][und]=[blocked-relay-node:nid]\\u0026edit[field_ip_address_blocking_event][und]=[blocked-relay-event-node:nid]\\r\\n\\r\\nBest regards,\\r\\nRemedy Admin Team"
          }
        }
      ]
    }
  }');
  $items['rules_notify_event_mitigation_failure'] = entity_import('rules_config', '{ "rules_notify_event_mitigation_failure" : {
      "LABEL" : "Notify Event Mitigation Failure",
      "PLUGIN" : "rule",
      "DO" : []
    }
  }');
  $items['rules_notify_event_mitigation_success'] = entity_import('rules_config', '{ "rules_notify_event_mitigation_success" : {
      "LABEL" : "Notify Event Mitigation Success",
      "PLUGIN" : "rule",
      "DO" : []
    }
  }');
  $items['rules_populate_dns_configuration_task_update_ip'] = entity_import('rules_config', '{ "rules_populate_dns_configuration_task_update_ip" : {
      "LABEL" : "Populate DNS Configuration Task (Update IP)",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "provision_relay_node" : { "label" : "Relay Node", "type" : "node" },
        "provision_event_node" : { "label" : "Event Node", "type" : "node" },
        "provision_task_node" : { "label" : "Task Node", "type" : "node" },
        "provision_domain_node" : { "label" : "Domain Node", "type" : "node" },
        "provision_output" : { "label" : "Output", "type" : "text" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "provision-event-node" ], "field" : "field_target" } },
        { "entity_has_field" : {
            "entity" : [ "provision-task-node" ],
            "field" : "field_ip_address_blocking_event"
          }
        },
        { "entity_has_field" : { "entity" : [ "provision-task-node" ], "field" : "field_data" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "provision-task-node:field-ip-address-blocking-event" ],
            "value" : [ "provision-event-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "provision-task-node:field-data" ],
            "value" : "[provision-output]"
          }
        },
        { "entity_save" : { "data" : [ "provision-task-node" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_populate_dns_task'] = entity_import('rules_config', '{ "rules_populate_dns_task" : {
      "LABEL" : "Populate Provision DNS Task",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php", "devel" ],
      "USES VARIABLES" : {
        "provision_data" : { "label" : "Provision Data", "type" : "text" },
        "provision_new_domain_node" : { "label" : "New Domain Node", "type" : "node" },
        "provision_event_node" : { "label" : "Event Node", "type" : "node" },
        "provision_task_node" : { "label" : "Task Node", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "provision-event-node" ], "field" : "field_target" } },
        { "entity_has_field" : { "entity" : [ "provision-task-node" ], "field" : "field_data" } },
        { "entity_has_field" : {
            "entity" : [ "provision-task-node" ],
            "field" : "field_dns_blocking_event"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "provision-task-node:field-data" ],
            "value" : "\\u003C?php echo \\u0022Output : \\u0022 . $provision_data; ?\\u003E"
          }
        },
        { "data_set" : {
            "data" : [ "provision-task-node:field-dns-blocking-event" ],
            "value" : [ "provision-event-node" ]
          }
        },
        { "devel_debug" : { "value" : [ "provision-event-node" ] } },
        { "entity_save" : { "data" : [ "provision-task-node" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_populate_ip_provision_task'] = entity_import('rules_config', '{ "rules_populate_ip_provision_task" : {
      "LABEL" : "Populate IP Address Provision Task",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "provision_data" : { "label" : "Provision Data", "type" : "text" },
        "provision_new_domain_node" : { "label" : "New Domain Node", "type" : "node" },
        "provision_event_node" : { "label" : "Event Node", "type" : "node" },
        "provision_task_node" : { "label" : "Task Node", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "provision-event-node" ], "field" : "field_target" } },
        { "entity_has_field" : { "entity" : [ "provision-task-node" ], "field" : "field_data" } },
        { "entity_has_field" : {
            "entity" : [ "provision-task-node" ],
            "field" : "field_dns_blocking_event"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "provision-task-node:field-data" ],
            "value" : "\\u003C?php echo \\u0022Output : \\u0022 . $provision_data; ?\\u003E"
          }
        },
        { "data_set" : {
            "data" : [ "provision-task-node:field-dns-blocking-event" ],
            "value" : [ "provision-event-node" ]
          }
        },
        { "entity_save" : { "data" : [ "provision-task-node" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_prompt_input_domain_name'] = entity_import('rules_config', '{ "rules_prompt_input_domain_name" : {
      "LABEL" : "Prompt Input Domain Name",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "DO" : [ { "redirect" : { "url" : "remedy\\/provision\\/domain" } } ]
    }
  }');
  $items['rules_prompt_input_ip_address'] = entity_import('rules_config', '{ "rules_prompt_input_ip_address" : {
      "LABEL" : "Prompt Input IP address",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "DO" : [ { "redirect" : { "url" : " remedy\\/provision\\/ip" } } ]
    }
  }');
  $items['rules_provision_dns'] = entity_import('rules_config', '{ "rules_provision_dns" : {
      "LABEL" : "Provision DNS",
      "PLUGIN" : "rule",
      "TAGS" : [ "dns", "provision" ],
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "provision_domain" : { "label" : "Domain To Provision", "type" : "text" },
        "provision_blocked_domain_nid" : { "label" : "Blocked Domain Nid", "type" : "integer" },
        "blocked_domain_event_nid" : { "label" : "Blocked Domain Event Nid", "type" : "integer" }
      },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "domain",
              "param_title" : "\\u003C?php echo $provision_domain; ?\\u003E",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "new_domain" : "New Domain Node" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "provision_dns_task",
              "param_title" : "DNS Provision : \\u003C?php echo $provision_domain; ?\\u003E",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "domain_provision_task" : "Domain Provision Task" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "dns_configuration_task",
              "param_title" : "Adding A entries for Domain \\u0022\\u003C?php echo $provision_domain; ?\\u003E\\u0022",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "dns_configuration_task" : "DNS Configuration Task" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "blocked-domain-event-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "blocked_domain_event_node" : "Blocked Domain Node" } }
          }
        },
        { "drupal_message" : { "message" : "The domain \\u0022\\u003C?php echo $provision_domain; ?\\u003E\\u0022 has successfully been created \\u0026 linked to the relay node." } },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "provision-blocked-domain-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "provision_blocked_domain_node" : "Blocked Domain Node" } }
          }
        },
        { "drupal_message" : { "message" : "Provisionning the new domain : \\u003C?php echo $provision_domain; ?\\u003E via DNSimple API." } },
        { "php_eval" : { "code" : "\\/\\/DNSimple domaine creation\\r\\n$d = new DNSimple;\\r\\n$r = $d-\\u003Edomains_create($provision_domain);\\r\\n\\r\\nrules_invoke_component(\\u0022rules_populate_dns_task\\u0022, serialize($r), $new_domain, $blocked_domain_event_node, $domain_provision_task);" } },
        { "drupal_message" : { "message" : "Linking new domain (\\u003C?php echo $provision_domain; ?\\u003E) to existing relay node." } },
        { "component_rules_update_domain_add_dns_entries" : {
            "update_new_domain" : [ "new-domain" ],
            "blocking_event_node" : [ "blocked-domain-event-node" ],
            "task_node" : [ "dns-configuration-task" ]
          }
        },
        { "component_rules_dns_mitigation_successful" : {
            "new_domain_node" : [ "new-domain" ],
            "event_node" : [ "blocked-domain-event-node" ]
          }
        },
        { "entity_save" : { "data" : [ "blocked-domain-event-node" ], "immediate" : 1 } },
        { "component_rules_dns_mitigation_marked_as_unsuccessful" : {
            "new_domain_node" : [ "new-domain" ],
            "event_node" : [ "blocked-domain-event-node" ]
          }
        },
        { "component_rules_provision_dns_health_monitoring" : {
            "provision_domain" : "\\u003C?php echo $provision_domain; ?\\u003E",
            "probe_ipaddress" : "1.2.3.4:28008"
          }
        },
        { "component_rules_update_domain_relays_entity_reference" : {
            "update_domain" : [ "provision-blocked-domain-node" ],
            "update_new_domain" : [ "new-domain" ],
            "update_blocking_event" : [ "blocked-domain-event-node" ]
          }
        }
      ]
    }
  }');
  $items['rules_provision_dns_health_monitoring'] = entity_import('rules_config', '{ "rules_provision_dns_health_monitoring" : {
      "LABEL" : "Provision DNS Health Monitoring",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "provision_domain" : { "label" : "Domain Name", "type" : "text" },
        "probe_ipaddress" : { "label" : "Probe IP address", "type" : "text" }
      },
      "DO" : [
        { "drupal_message" : {
            "message" : "Provisionning DNS Health Monitoring for \\u003C?php echo $provision_domain; ?\\u003E on probe \\u003C?php echo $probe_ipaddress; ?\\u003E",
            "repeat" : 0
          }
        },
        { "php_eval" : { "code" : "\\/\\/Adding domains for Health Monitoring\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe_ipaddress, array(\\u0022operate_asset\\u0022 =\\u003E array(\\u0022add_asset\\u0022, \\u0022domain\\u0022, $provision_domain)));\\r\\n" } }
      ]
    }
  }');
  $items['rules_provision_ip_address_health_monitoring'] = entity_import('rules_config', '{ "rules_provision_ip_address_health_monitoring" : {
      "LABEL" : "Provision IP Address Health Monitoring",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : {
        "provision_ip_address" : { "label" : "IP address", "type" : "text" },
        "probe_ipaddress" : { "label" : "Probe IP address", "type" : "text" }
      },
      "DO" : [
        { "drupal_message" : { "message" : "Provisionning DNS Health Monitoring for \\u003C?php echo $domain; ?\\u003E on probe \\u003C?php echo $pbobe; ?\\u003E" } },
        { "php_eval" : { "code" : "\\/\\/Adding IP addresses for Health Monitoring\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe_ipaddress, array(\\u0022operate_asset\\u0022 =\\u003E array(\\u0022delete_asset\\u0022, \\u0022ip\\u0022, $provision_ip_address)));" } }
      ]
    }
  }');
  $items['rules_provision_ipaddress'] = entity_import('rules_config', '{ "rules_provision_ipaddress" : {
      "LABEL" : "Provision IP Address",
      "PLUGIN" : "rule",
      "TAGS" : [ "dns", "provision" ],
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "blocked_relay" : { "label" : "Blocked Relay", "type" : "node" },
        "blocked_relay_event" : { "label" : "Blocked Relay Event", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "blocked-relay" ], "field" : "field_ip_address" } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Replacing IP Address : [blocked-relay:field-ip-address]" } },
        { "php_eval" : { "code" : "  \\/\\/API Call for provisionning IP address on EC2 instance\\r\\n  libraries_load(\\u0027awssdk\\u0027);\\r\\n\\r\\n  $ip_address = $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n  $instanceid_ec2 = $blocked_relay-\\u003Efield_instanceid_ec2[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n\\r\\n  $ec2 = new AmazonEC2();\\r\\n\\r\\n  $response = $ec2-\\u003Edisassociate_address($ip_address);\\r\\n  $response = $ec2-\\u003Erelease_address(array(\\u0027PublicIp\\u0027 =\\u003E $ip_address));\\r\\n  $response = $ec2-\\u003Eallocate_address();\\r\\n\\r\\n  $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027] = strval($response-\\u003Ebody-\\u003EpublicIp);\\r\\n  $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027safe_value\\u0027] = strval($response-\\u003Ebody-\\u003EpublicIp);\\r\\n\\r\\n  $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027] = strval($response-\\u003Ebody-\\u003EpublicIp);\\r\\n  $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027safe_value\\u0027] = strval($response-\\u003Ebody-\\u003EpublicIp);\\r\\n\\r\\n  $response = $ec2-\\u003Eassociate_address($instanceid_ec2, strval($response-\\u003Ebody-\\u003EpublicIp));\\r\\n\\r\\n  $response = $ec2-\\u003Edescribe_instances(array(\\u0027InstanceId\\u0027 =\\u003E $instanceid_ec2));\\r\\n\\r\\n  $blocked_relay-\\u003Efield_host[\\u0027und\\u0027][0][\\u0027value\\u0027] = strval($response-\\u003Ebody-\\u003EreservationSet-\\u003Eitem-\\u003EinstancesSet-\\u003Eitem-\\u003EdnsName);\\r\\n  $blocked_relay-\\u003Efield_host[\\u0027und\\u0027][0][\\u0027safe_value\\u0027] = strval($response-\\u003Ebody-\\u003EreservationSet-\\u003Eitem-\\u003EinstancesSet-\\u003Eitem-\\u003EdnsName);\\r\\n  $blocked_relay-\\u003Etitle = $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027] . \\u0022 (\\u0022 . $blocked_relay-\\u003Efield_host[\\u0027und\\u0027][0][\\u0027value\\u0027] . \\u0022)\\u0022;\\r\\n" } },
        { "entity_save" : { "data" : [ "blocked-relay" ], "immediate" : 1 } },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "ip_configuration_task",
              "param_title" : "New IP configuration for blocked relay : [blocked-relay:field-ip-address]",
              "param_author" : "1"
            },
            "PROVIDE" : { "entity_created" : { "ipaddress_configuration_task" : "IP Address Configuration task" } }
          }
        },
        { "component_rules_ip_configuration_task" : {
            "provision_relay_node" : [ "blocked-relay" ],
            "provision_event_node" : [ "blocked-relay-event" ],
            "provision_task_node" : [ "ipaddress-configuration-task" ]
          }
        },
        { "drupal_message" : { "message" : "New IP address Allocated : [blocked-relay:field-ip-address]" } },
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Cnode\\u003E" },
            "PROVIDE" : { "variable_added" : { "linked_domains" : "Domains linked to node" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_domain_relays",
              "value" : [ "blocked-relay:nid" ],
              "limit" : "25"
            },
            "PROVIDE" : { "entity_fetched" : { "linked_domain_nodes" : "Linked Domains Nodes" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "linked-domain-nodes" ] },
            "ITEM" : { "blocked_relay_domain" : "Blocked Relay Domain" },
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "node",
                    "param_type" : "dns_configuration_task",
                    "param_title" : "DNS Configuration for IP Address : [blocked-relay:field-ip-address] on domain [blocked-relay-domain:title]",
                    "param_author" : "1"
                  },
                  "PROVIDE" : { "entity_created" : { "dns_configuration_task" : "DNS Configuration Task" } }
                }
              },
              { "entity_save" : { "data" : [ "dns-configuration-task" ], "immediate" : 1 } },
              { "php_eval" : { "code" : "\\/\\/Update all DNS entries for linked domains\\r\\n\\r\\n$ip_address = $blocked_relay-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n\\r\\n$d = new DNSimple;\\r\\n$r = array();\\r\\n\\r\\n$records = $d-\\u003Edns_list($blocked_relay_domain-\\u003Etitle);\\r\\n\\r\\nforeach($records as $key=\\u003E$val){\\r\\n$r[] = $d-\\u003Edns_update($blocked_relay_domain-\\u003Etitle, $key, array(\\u0027name\\u0027 =\\u003E \\u0022www\\u0022, \\u0027record_type\\u0027   =\\u003E \\u0027A\\u0027 , \\u0027content\\u0027 =\\u003E $ip_address, \\u0027prio\\u0027 =\\u003E \\u0027\\u0027, \\u0027ttl\\u0027 =\\u003E 3600));\\r\\n}\\r\\n\\/*\\r\\nrules_invoke_component(\\u0022rules_populate_dns_configuration_task_update_ip\\u0022, serialize($r), $blocked_relay_domain, $blocked_relay, $blocked_relay_event, $dns_configuration_task);*\\/" } },
              { "drupal_message" : { "message" : "DNS Configuration for IP Address : [blocked-relay:field-ip-address] on domain [blocked-relay-domain:title]" } },
              { "component_rules_populate_dns_configuration_task_update_ip" : {
                  "provision_relay_node" : [ "blocked-relay" ],
                  "provision_event_node" : [ "blocked-relay-event" ],
                  "provision_task_node" : [ "dns-configuration-task" ],
                  "provision_domain_node" : [ "blocked-relay-domain" ],
                  "provision_output" : "Test"
                }
              }
            ]
          }
        },
        { "component_rules_ip_address_mitigation_marked_as_successful" : {
            "relay_node" : [ "blocked-relay" ],
            "event_node" : [ "blocked-relay-event" ]
          }
        },
        { "component_rules_ip_address_mitigation_marked_as_unsuccessful" : {
            "relay_node" : [ "blocked-relay" ],
            "event_node" : [ "blocked-relay-event" ]
          }
        }
      ]
    }
  }');
  $items['rules_provision_ssl'] = entity_import('rules_config', '{ "rules_provision_ssl" : { "LABEL" : "Provision SSL", "PLUGIN" : "rule", "DO" : [] } }');
  $items['rules_provisionning_new_domain_name'] = entity_import('rules_config', '{ "rules_provisionning_new_domain_name" : {
      "LABEL" : "Provisionning New Domain Name",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : [ "entityform_insert" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_blocked_domain" } },
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_blocking_event" } },
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_domain_name" } }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_exec_dns_blocking_as" : {
            "domain" : [ "entityform:field-domain-name:url" ],
            "blocked_domain_nid" : [ "entityform:field-blocked-domain:nid" ],
            "blocked_domain_event_nid" : [ "entityform:field-blocking-event:nid" ]
          }
        }
      ]
    }
  }');
  $items['rules_provisionning_new_ipaddress'] = entity_import('rules_config', '{ "rules_provisionning_new_ipaddress" : {
      "LABEL" : "Provisionning New IP Address",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : [ "entityform_insert" ],
      "IF" : [
        { "NOT entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_domain_name" } },
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_relays" } },
        { "entity_has_field" : {
            "entity" : [ "entityform" ],
            "field" : "field_ip_address_blocking_event"
          }
        }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_exec_ipaddress_blockin" : {
            "blocked_relay" : [ "entityform:field-relays" ],
            "blocked_relay_event" : [ "entityform:field-ip-address-blocking-event" ]
          }
        }
      ]
    }
  }');
  $items['rules_purchase_new_domain_name'] = entity_import('rules_config', '{ "rules_purchase_new_domain_name" : {
      "LABEL" : "Purchase new domain name",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "php", "rules", "wsclient" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "php_eval" : { "code" : "dsm($node-\\u003Etype);\\r\\nreturn $node-\\u003Etype = \\u0022action\\u0022;" } }
      ],
      "DO" : [
        { "wsclient_dns_simple_check" : {
            "USING" : { "param_domainname" : "\\u003C?php \\r\\n\\/\\/dprint_r($node-\\u003Efield_value);\\r\\n\\/\\/echo $node-\\u003Efield_value\\u0027]; \\r\\necho \\u0022internews.eu\\u0022;\\r\\n?\\u003E" },
            "PROVIDE" : { "result" : { "result" : "Availability" } }
          }
        },
        { "drupal_message" : { "message" : "\\u003C?php echo dprint_r($result,true) ?\\u003E" } }
      ]
    }
  }');
  $items['rules_test_domain'] = entity_import('rules_config', '{ "rules_test_domain" : {
      "LABEL" : "Check If Domain Is Blocked",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "domain_to_test" : { "label" : "Domain To Test", "type" : "text" },
        "probe" : { "label" : "Probe", "type" : "text" }
      },
      "AND" : [
        { "php_eval" : { "code" : "\\/\\/Check on probe if input domain is blocked\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe, array(\\u0022test_asset\\u0022 =\\u003E array(\\u0022dns_injection\\u0022, $domain_to_test)));\\r\\nif ($result[1] == \\u0022True\\u0022){\\r\\nreturn true;\\r\\n}" } }
      ]
    }
  }');
  $items['rules_test_ipaddress'] = entity_import('rules_config', '{ "rules_test_ipaddress" : {
      "LABEL" : "Condition IP Address Is Blocked",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "ip_address_to_test" : { "label" : "IP Address To Test", "type" : "text" },
        "probe" : { "label" : "Probe", "type" : "text" }
      },
      "AND" : [
        { "php_eval" : { "code" : "\\/\\/Check on probe if input domain is blocked\\r\\n\\r\\nreturn true;\\r\\n\\r\\n$result = xmlrpc(\\u0022http:\\/\\/\\u0022 . $probe, array(\\u0022test_asset\\u0022 =\\u003E array(\\u0022ip_block\\u0022, $ip_address_to_test)));\\r\\nif ($result[1] == \\u0022True\\u0022){\\r\\nreturn true;\\r\\n}" } }
      ]
    }
  }');
  $items['rules_testing_new_dns'] = entity_import('rules_config', '{ "rules_testing_new_dns" : {
      "LABEL" : "Testing new DNS",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "dns_blocking" ],
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "workflow_check_transition" : {
            "node" : [ "node" ],
            "old_state" : { "value" : { "4" : "4" } },
            "new_state" : { "value" : { "3" : "3" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "8. Test if Health Monitoring Infra is sending positive test results. -\\u003E Notify Results to Site admin 10." } },
        { "workflow_rules_set_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "6" : "6" } } } }
      ]
    }
  }');
  $items['rules_update_domain_add_dns_entries'] = entity_import('rules_config', '{ "rules_update_domain_add_dns_entries" : {
      "LABEL" : "Add DNS Entries To New Provisionned Domain",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "update_new_domain" : { "label" : "New Domain", "type" : "node" },
        "blocking_event_node" : { "label" : "Event Node", "type" : "node" },
        "task_node" : { "label" : "Task Node", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "update-new-domain" ], "field" : "field_domain_relays" } },
        { "entity_has_field" : { "entity" : [ "task-node" ], "field" : "field_dns_blocking_event" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "nid",
              "value" : [ "update-new-domain:field-domain-relays:0:nid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "relay_node" : "Relay Node" } }
          }
        },
        { "php_eval" : { "code" : "\\/\\/DNSimple www A record entry\\r\\n$d = new DNSimple;\\r\\n$r = $d-\\u003Edns_create($update_new_domain-\\u003Etitle, array(\\r\\n\\t\\t\\t\\t\\t\\u0027name\\u0027\\t\\t=\\u003E\\t\\u0022www\\u0022,\\r\\n\\t\\t\\t\\t\\t\\u0027record_type\\u0027\\t=\\u003E\\t\\u0022A\\u0022,\\r\\n\\t\\t\\t\\t\\t\\u0027content\\u0027\\t=\\u003E\\t$relay_node[0]-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027],\\r\\n\\t\\t\\t\\t\\t\\u0027prio\\u0027\\t\\t=\\u003E\\t\\u0027\\u0027 ,\\r\\n\\t\\t\\t\\t\\t\\u0027ttl\\u0027\\t\\t=\\u003E\\t3600\\r\\n\\t\\t\\t\\t));\\r\\n$r2 = $d-\\u003Edns_create($update_new_domain-\\u003Etitle, array(\\r\\n\\t\\t\\t\\t\\t\\u0027name\\u0027\\t\\t=\\u003E\\t\\u0027\\u0027,\\r\\n\\t\\t\\t\\t\\t\\u0027record_type\\u0027\\t=\\u003E\\t\\u0022A\\u0022,\\r\\n\\t\\t\\t\\t\\t\\u0027content\\u0027\\t=\\u003E\\t$relay_node[0]-\\u003Efield_ip_address[\\u0027und\\u0027][0][\\u0027value\\u0027],\\r\\n\\t\\t\\t\\t\\t\\u0027prio\\u0027\\t\\t=\\u003E\\t\\u0027\\u0027 ,\\r\\n\\t\\t\\t\\t\\t\\u0027ttl\\u0027\\t\\t=\\u003E\\t3600\\r\\n\\t\\t\\t\\t));\\r\\n\\/\\/rules_invoke_component(\\u0022rules_populate_dns_task\\u0022, serialize($r) . serialize($r), $update_new_domain, $blocking_event_node, $task_node);" } },
        { "data_set" : {
            "data" : [ "task-node:field-dns-blocking-event" ],
            "value" : [ "blocking-event-node" ]
          }
        },
        { "entity_save" : { "data" : [ "task-node" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_update_domain_relays_entity_reference'] = entity_import('rules_config', '{ "rules_update_domain_relays_entity_reference" : {
      "LABEL" : "Update Domain_Relays Entity Reference",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "update_domain" : { "label" : "Domain", "type" : "node" },
        "update_new_domain" : { "label" : "New Domain", "type" : "node" },
        "update_blocking_event" : { "label" : "Event", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "update-domain" ], "field" : "field_domain_relays" } },
        { "entity_has_field" : { "entity" : [ "update-new-domain" ], "field" : "field_domain_relays" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "nid",
              "value" : [ "update-domain:field-domain-relays:0:nid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "relay_node" : "Relay Node" } }
          }
        },
        { "php_eval" : { "code" : "$update_new_domain-\\u003Efield_domain_relays[\\u0027und\\u0027][0][\\u0027target_id\\u0027] = $relay_node[0]-\\u003Enid;\\r\\n" } },
        { "entity_save" : { "data" : [ "update-new-domain" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_validating_dns_changing'] = entity_import('rules_config', '{ "rules_validating_dns_changing" : {
      "LABEL" : "Validating DNS changing",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_comment_added" ],
      "IF" : [
        { "workflow_check_transition" : {
            "node" : [ "node" ],
            "old_state" : { "value" : { "3" : "3" } },
            "new_state" : { "value" : { "6" : "6" } }
          }
        },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : []
    }
  }');
  return $items;
}
