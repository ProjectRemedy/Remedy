<?php
/**
 * @file
 * remedy_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function remedy_core_default_rules_configuration() {
  $items = array();
  $items['rules_domain_node_creation_provision_health_monitoring'] = entity_import('rules_config', '{ "rules_domain_node_creation_provision_health_monitoring" : {
      "LABEL" : "Domain Node Creation : Provision Health Monitoring",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "domain" : "domain" } } } }
      ],
      "DO" : [
        { "component_rules_provision_dns_health_monitoring" : {
            "provision_domain" : "[node:title]",
            "probe_ipaddress" : "1.2.3.4:28008"
          }
        }
      ]
    }
  }');
  $items['rules_domain_node_deletion_de_provision_health_monitoring'] = entity_import('rules_config', '{ "rules_domain_node_deletion_de_provision_health_monitoring" : {
      "LABEL" : "Domain Node Deletion: De-provision Health Monitoring",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_delete" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "domain" : "domain" } } } }
      ],
      "DO" : [
        { "component_rules_deprovision_dns_health_monitoring" : {
            "provision_domain" : "$node-\\u003Etitle",
            "probe_ipaddress" : "1.2.3.4:28008"
          }
        }
      ]
    }
  }');
  $items['rules_monitor_domain_name_cron'] = entity_import('rules_config', '{ "rules_monitor_domain_name_cron" : {
      "LABEL" : "Monitor Domain Name Cron",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "component_rules_test_domain" : {
            "domain_to_test" : "[entityform:field-testing-domain]",
            "probe" : "probe1"
          }
        },
        { "NOT entity_has_field" : { "entity" : [ "node" ], "field" : "field_blocking_event" } },
        { "data_is" : { "data" : [ "node:type" ], "value" : "domain" } }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_init_dns_blocking" : {
            "blocked_domain" : [ "node:title" ],
            "check_data" : "[Health Monitoring Output]",
            "blocked_domain_nid" : [ "node:nid" ]
          }
        }
      ]
    }
  }');
  $items['rules_monitor_ip_address_cron'] = entity_import('rules_config', '{ "rules_monitor_ip_address_cron" : {
      "LABEL" : "Monitor IP Address Cron",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "component_rules_test_ipaddress" : { "ip_address_to_test" : "[node:field-ip-address]\\t", "probe" : "probe1" } },
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_init_ipaddress_blocking" : { "blocked_relay_node" : [ "node" ], "check_data" : "Test" } }
      ]
    }
  }');
  $items['rules_monitor_ipaddress'] = entity_import('rules_config', '{ "rules_monitor_ipaddress" : {
      "LABEL" : "Monitor IP Address ",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "entityform" ],
      "ON" : [ "entityform_insert" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_relays" } },
        { "component_rules_test_ipaddress" : {
            "ip_address_to_test" : "[entityform:field-new-ip-address]",
            "probe" : "probe1"
          }
        },
        { "NOT entity_has_field" : {
            "entity" : [ "entityform" ],
            "field" : "field_ip_address_blocking_event"
          }
        }
      ],
      "DO" : [
        { "component_rules_mitigation_sequence_init_ipaddress_blocking" : {
            "blocked_relay_node" : [ "entityform:field-relays" ],
            "check_data" : "Test"
          }
        }
      ]
    }
  }');
  $items['rules_relay_node_creation_provision_health_monitoring'] = entity_import('rules_config', '{ "rules_relay_node_creation_provision_health_monitoring" : {
      "LABEL" : "Relay Node Creation : Provision Health Monitoring",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : [
        { "component_rules_provision_ip_address_health_monitoring" : {
            "provision_ip_address" : "[node:field-ip-address]\\t",
            "probe_ipaddress" : "1.2.3.4:28008"
          }
        }
      ]
    }
  }');
  $items['rules_relay_node_deletion_de_provision_health_monitoring'] = entity_import('rules_config', '{ "rules_relay_node_deletion_de_provision_health_monitoring" : {
      "LABEL" : "Relay Node Deletion: De-provision Health Monitoring",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_delete" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } }
      ],
      "DO" : [
        { "component_rules_deprovision_ip_address_health_monitoring" : {
            "provision_ip_address" : "[node:field-ip-address]",
            "probe_ipaddress" : "1.2.3.4:28008"
          }
        }
      ]
    }
  }');
  $items['rules_relay_node_update_provision_health_monitoring'] = entity_import('rules_config', '{ "rules_relay_node_update_provision_health_monitoring" : {
      "LABEL" : "Relay Node Update : Provision Health Monitoring",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "relay" : "relay" } } } },
        { "NOT data_is" : {
            "data" : [ "node:field-ip-address" ],
            "value" : "[node-unchanged:field-ip-address]"
          }
        }
      ],
      "DO" : [
        { "component_rules_provision_ip_address_health_monitoring" : {
            "provision_ip_address" : "[node:field-ip-address]\\t",
            "probe_ipaddress" : "1.2.3.4:2800"
          }
        }
      ]
    }
  }');
  return $items;
}
