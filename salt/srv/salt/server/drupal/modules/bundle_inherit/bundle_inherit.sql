DROP TABLE IF EXISTS `bundle_inherit`;
CREATE TABLE IF NOT EXISTS `bundle_inherit` (
  `entity_type` varchar(255) NOT NULL COMMENT 'The entity type of the bundles.',
  `bundle` varchar(255) NOT NULL COMMENT 'Child bundle name.',
  `bundle_parent` varchar(255) NOT NULL COMMENT 'Parent bundle name.',
  PRIMARY KEY (`entity_type`,`bundle`),
  KEY `parent` (`entity_type`,`bundle_parent`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Holds info about hierarchy relations between entity types.';

--
-- Dumping data for table `bundle_inherit`
--

INSERT INTO `bundle_inherit` (`entity_type`, `bundle`, `bundle_parent`) VALUES
('comment', 'comment_node_account', ''),
('comment', 'comment_node_action_type', ''),
('comment', 'comment_node_article', ''),
('comment', 'comment_node_configuration_task', ''),
('comment', 'comment_node_credit_task', ''),
('comment', 'comment_node_distribution', ''),
('comment', 'comment_node_dns_configuration_task', ''),
('comment', 'comment_node_domain', ''),
('comment', 'comment_node_domain_testing_task', ''),
('comment', 'comment_node_event', ''),
('comment', 'comment_node_event_dns_blocked', ''),
('comment', 'comment_node_event_ip_blocked', ''),
('comment', 'comment_node_health_monitoring_config_task', ''),
('comment', 'comment_node_ip_configuration_task', ''),
('comment', 'comment_node_ip_testing_task', ''),
('comment', 'comment_node_notification_task_', ''),
('comment', 'comment_node_page', ''),
('comment', 'comment_node_probe', ''),
('comment', 'comment_node_provisioning_task', ''),
('comment', 'comment_node_provision_dns_task', ''),
('comment', 'comment_node_provision_ssl_task', ''),
('comment', 'comment_node_provision_vps_task', ''),
('comment', 'comment_node_relay', ''),
('comment', 'comment_node_relay_configuration_task', ''),
('comment', 'comment_node_relay_testing_task', ''),
('comment', 'comment_node_run_instance_task', ''),
('comment', 'comment_node_site', ''),
('comment', 'comment_node_ssl_configuration_task', ''),
('comment', 'comment_node_task', ''),
('comment', 'comment_node_tenant', ''),
('comment', 'comment_node_terminate_instance_task', ''),
('comment', 'comment_node_test_task', ''),
('comment', 'comment_node_virtual_host_configuration_task', ''),
('comment', 'comment_node_vps_configuration_task', ''),
('comment', 'comment_node_web_proxy_configuration_task', ''),
('comment', 'comment_node_web_server_configuration_task', ''),
('entityform', 'prompt_input_domain_name', ''),
('entityform', 'prompt_input_ip_address', ''),
('entityform', 'testing_mitigation_component', ''),
('entityform', 'testing_rules_components', ''),
('entityform', 'test_ipaddress_block_mitigation', ''),
('file', 'file', ''),
('node', 'account', ''),
('node', 'action_type', ''),
('node', 'article', ''),
('node', 'distribution', ''),
('node', 'domain', ''),
('node', 'event', ''),
('node', 'page', ''),
('node', 'probe', ''),
('node', 'relay', ''),
('node', 'site', ''),
('node', 'task', ''),
('node', 'tenant', ''),
('node', 'dns_configuration_task', 'configuration_task'),
('node', 'health_monitoring_config_task', 'configuration_task'),
('node', 'relay_configuration_task', 'configuration_task'),
('node', 'ssl_configuration_task', 'configuration_task'),
('node', 'vps_configuration_task', 'configuration_task'),
('node', 'event_dns_blocked', 'event'),
('node', 'event_ip_blocked', 'event'),
('node', 'provision_dns_task', 'provisioning_task'),
('node', 'provision_ssl_task', 'provisioning_task'),
('node', 'provision_vps_task', 'provisioning_task'),
('node', 'run_instance_task', 'provision_vps_task'),
('node', 'terminate_instance_task', 'provision_vps_task'),
('node', 'ip_configuration_task', 'relay_configuration_task'),
('node', 'virtual_host_configuration_task', 'relay_configuration_task'),
('node', 'web_proxy_configuration_task', 'relay_configuration_task'),
('node', 'web_server_configuration_task', 'relay_configuration_task'),
('node', 'configuration_task', 'task'),
('node', 'credit_task', 'task'),
('node', 'notification_task_', 'task'),
('node', 'provisioning_task', 'task'),
('node', 'test_task', 'task'),
('node', 'domain_testing_task', 'test_task'),
('node', 'ip_testing_task', 'test_task'),
('node', 'relay_testing_task', 'test_task'),
('rules_config', 'rules_config', ''),
('rules_link', 'rules_link', ''),
('taxonomy_term', 'distribution', ''),
('taxonomy_term', 'instance_type', ''),
('taxonomy_term', 'provider', ''),
('taxonomy_term', 'resource_type', ''),
('taxonomy_term', 'tags', ''),
('taxonomy_vocabulary', 'taxonomy_vocabulary', ''),
('user', 'user', ''),
('wsclient_service', 'wsclient_service', '');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

