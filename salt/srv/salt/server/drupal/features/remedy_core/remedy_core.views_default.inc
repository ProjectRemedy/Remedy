<?php
/**
 * @file
 * remedy_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function remedy_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table_grouped_relationship';
  $handler->display->display_options['style_options']['columns'] = array(
    'php_4' => 'php_4',
    'php_5' => 'php_5',
    'php_1' => 'php_1',
    'title' => 'title',
    'nid_1' => 'nid_1',
    'title_1' => 'title_1',
    'nid' => 'nid',
    'field_resource_type_1' => 'field_resource_type_1',
    'title_2' => 'title_2',
    'field_host' => 'field_host',
    'field_resource_type' => 'field_resource_type',
    'nid_2' => 'nid_2',
    'title_5' => 'title_5',
    'php' => 'php',
    'php_6' => 'php_6',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'domain_blocked_link' => 'domain_blocked_link',
    'php_11' => 'php_11',
    'php_8' => 'php_8',
    'php_7' => 'php_7',
    'php_12' => 'php_12',
    'php_9' => 'php_9',
    'php_10' => 'php_10',
  );
  $handler->display->display_options['style_options']['default'] = 'php_1';
  $handler->display->display_options['style_options']['info'] = array(
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_host' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_5' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_6' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'domain_blocked_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_11' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_8' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_7' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_12' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_9' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_10' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['grouped_relationships'] = array(
    'base' => 0,
    'field_domain_relays_target_id' => 0,
    'field_relay_target_site_target_id' => 0,
    'reverse_field_target_node' => 0,
    'reverse_field_target_domain_node' => 0,
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_sites_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  /* Field: Content: Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Requests';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '//$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
//$data_rrd = rrd_fetch($file, $opts);
$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][360];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'IP Blocking';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'DNS Blocking';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
$ret = dprint_r($relay,true);
return $ret;';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
echo value;
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Traffic Graph';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
$directory = "sites/default/files" . "/{$host}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $host . " nginx requests",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');   
  $output = "<em>No Data Available</em>";
}
return $output;';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print $value;
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Health Graph ';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
$directory = "sites/default/files" . "/{$ip}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current-health.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $ip . " IP Block Monitoring",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');    
  $output = "<em>No Data Available</em>";
}

return $output;';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if ($row->php_4 =="1") {
return "Blocked";
}
else {
return "Accessible";
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
//print render(drupal_get_form(\'mitigate_action_form\'));
echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_domain_relays_target_id';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = '';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'domain' => 'domain',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Relay type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['filters']['field_resource_type_tid']['value'] = array(
    4 => '4',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Relay type';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Distribution Type (field_distribution_type) */
  $handler->display->display_options['filters']['field_distribution_type_tid']['id'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['table'] = 'field_data_field_distribution_type';
  $handler->display->display_options['filters']['field_distribution_type_tid']['field'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['filters']['field_distribution_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['operator_id'] = 'field_distribution_type_tid_op';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['label'] = 'Distribution Type';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['operator'] = 'field_distribution_type_tid_op';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['identifier'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_distribution_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distribution_type_tid']['vocabulary'] = 'distribution';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['id'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['table'] = 'field_data_field_relay_target_site';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['field'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['label'] = 'Relay_Target_Site';
  /* Relationship: DNS_Blocking_Event */
  $handler->display->display_options['relationships']['reverse_field_target_node']['id'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['field'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['ui_name'] = 'DNS_Blocking_Event';
  $handler->display->display_options['relationships']['reverse_field_target_node']['label'] = 'DNS_Blocking_Event';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['id'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['field'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['label'] = 'Campain_Domain';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'IP Blocking';
  $handler->display->display_options['fields']['php_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
$domain = $row->title;
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/" . $domain . "/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'DNS Blocking';
  $handler->display->display_options['fields']['php_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
$domain = $row->title;
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/" .$domain. "/DNSTamper.rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
//$ret = dprint_r($relay,true);
return $ret;';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if ($row->php_4 =="1") {
return "<b style=\'color:red;\'>Blocked</b>";
}
else {
return "<b style=\'color:green;\'>Accessible</b>";
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
//print render(drupal_get_form(\'mitigate_action_form\'));
echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Domain Nid';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'Relay Nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  /* Field: Content: Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['fields']['nid_2']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_5']['id'] = 'title_5';
  $handler->display->display_options['fields']['title_5']['table'] = 'node';
  $handler->display->display_options['fields']['title_5']['field'] = 'title';
  $handler->display->display_options['fields']['title_5']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['fields']['title_5']['label'] = 'Campaign';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Relay Requests';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";

$opts = array ("AVERAGE", "-r", "26350", "-s", 1326904100);
$distrib_requests = rrd_fetch($file, $opts);
$total = 0;
foreach ($distrib_requests["data"]["value"] as $key => $val){
  if(!is_nan($val)){
    $total = $total + floatval($val)*26350;
  }
}

return $total;

/*$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];*/';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo(number_format($value));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Relay Active Connections';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_value'] = '//$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_connections-active.rrd";
//$data_rrd = rrd_fetch($file, $opts);
$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][360];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Traffic Graph';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
$directory = "sites/default/files" . "/{$host}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $host . " nginx requests",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');   
  $output = "<em>No Data Available</em>";
}
return $output;';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print $value;
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Health Graph ';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
$directory = "sites/default/files" . "/{$ip}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current-health.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $ip . " IP Block Monitoring",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');    
  $output = "<em>No Data Available</em>";
}

return $output;';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: DNS Mitigation */
  $handler->display->display_options['fields']['domain_blocked_link']['id'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['domain_blocked_link']['field'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['label'] = 'Report As Blocked';
  $handler->display->display_options['fields']['domain_blocked_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['domain_blocked_link']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_11']['id'] = 'php_11';
  $handler->display->display_options['fields']['php_11']['table'] = 'views';
  $handler->display->display_options['fields']['php_11']['field'] = 'php';
  $handler->display->display_options['fields']['php_11']['label'] = 'Mark as Blocked (Domain)';
  $handler->display->display_options['fields']['php_11']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_11']['php_output'] = '<?php global $base_url; ?>
<a href="<?php echo $base_url; ?>/eform/submit/testing-mitigation-component?edit[field_testing_domain][und]=<?php echo $row->nid_1; ?>">Mark as blocked</a>';
  $handler->display->display_options['fields']['php_11']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_11']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Last Unresolved DNS Blocking Event';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = '$event_node = "";
$query = new EntityFieldQuery();
  $query->entityCondition("entity_type", "node")
        ->entityCondition("bundle", "event_dns_blocked")
        ->propertyCondition("status", 1)
        ->fieldCondition("field_target", "target_id", $row->nid_1);
  $result = $query->execute();

if(isset($result[\'node\'])){
  foreach($result[\'node\'] as $key => $val) {
    $node = node_load($val->nid);
    if($node->workflow == 13 || $node->workflow == 14 || $node->workflow == 15){
      $event_node =  $node->nid;
    }
  }
}
return $event_node ;';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
global $base_url;
if((int)$value > 0){
echo(\'<a href="\' . $base_url . \'/node/\' . $value . \'">Link</a>\'); 
}
?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'Mitigate DNS Blocking';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_value'] = 'global $base_url;
if((int)$row->php_8 > 0){
if ($row->php_4 =="1") {
return \'<a href="\' . $base_url . \'/remedy/provision/domain?edit[field_blocked_domain][und]=\' . $row->nid_1 . \'&edit[field_blocking_event][und]=\' . $row->php_8 . \'">Click Here</a>\';
}
else {
return \'<a href="/drupal/remedy/provision/domain?edit[field_blocked_domain][und]=\' . $row->nid_1 . \'&edit[field_blocking_event][und]=\' . $row->php_8. \'">Click Here</a>\';
}
}';
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_12']['id'] = 'php_12';
  $handler->display->display_options['fields']['php_12']['table'] = 'views';
  $handler->display->display_options['fields']['php_12']['field'] = 'php';
  $handler->display->display_options['fields']['php_12']['label'] = 'Mark as Blocked (IP)';
  $handler->display->display_options['fields']['php_12']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_12']['php_output'] = '<?php
global $base_url;
?>
<a href="<?php echo $base_url; ?>/eform/submit/test-ipaddress-block-mitigation?edit[field_relays][und]=<?php echo $row->nid; ?>">Mark as blocked</a>';
  $handler->display->display_options['fields']['php_12']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_12']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['label'] = 'Last Unresolved IP Blocking Event';
  $handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_9']['php_value'] = '$event_node = "";
$query = new EntityFieldQuery();
  $query->entityCondition("entity_type", "node")
        ->entityCondition("bundle", "event_ip_blocked")
        ->propertyCondition("status", 1)
        ->fieldCondition("field_target", "target_id", $row->nid);
  $result = $query->execute();
if(isset($result[\'node\'])){
  foreach($result[\'node\'] as $key => $val) {
    $node = node_load($val->nid);
    if($node->workflow == 13 || $node->workflow == 14 || $node->workflow == 15){
      $event_node =  $node->nid;
    }
  }
}
return $event_node ;';
  $handler->display->display_options['fields']['php_9']['php_output'] = '<?php
global $base_url;
if((int)$value > 0){
echo(\'<a href="\' . $base_url . \'/node/\' . $value . \'">Link</a>\'); 
}
?>';
  $handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_10']['id'] = 'php_10';
  $handler->display->display_options['fields']['php_10']['table'] = 'views';
  $handler->display->display_options['fields']['php_10']['field'] = 'php';
  $handler->display->display_options['fields']['php_10']['label'] = 'Mitigate IP Blocking';
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_value'] = 'global $base_url;
if((int)$row->php_8 > 0){

if ($row->php_4 =="1") {
return \'<a href="\' . $base_url . \'/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_9 . \'">Click Here</a>\';
}
else {
return \'<a href="/drupal/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_9 . \'">Click Here</a>\';
}
}';
  $handler->display->display_options['fields']['php_10']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_10']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_10']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['path'] = 'dashboard_advanced';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Dashboard (advanced)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['dashboard'] = $view;

  $view = new view();
  $view->name = 'dashboard_overview_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dashboard (overview)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table_grouped_relationship';
  $handler->display->display_options['style_options']['columns'] = array(
    'php_4' => 'php_4',
    'php_5' => 'php_5',
    'php_1' => 'php_1',
    'title' => 'title',
    'nid_1' => 'nid_1',
    'title_1' => 'title_1',
    'nid' => 'nid',
    'field_resource_type_1' => 'field_resource_type_1',
    'title_2' => 'title_2',
    'field_host' => 'field_host',
    'field_resource_type' => 'field_resource_type',
    'nid_2' => 'nid_2',
    'title_5' => 'title_5',
    'php' => 'php',
    'php_6' => 'php_6',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'domain_blocked_link' => 'domain_blocked_link',
    'php_11' => 'php_11',
    'php_8' => 'php_8',
    'php_7' => 'php_7',
    'php_12' => 'php_12',
    'php_9' => 'php_9',
    'php_10' => 'php_10',
  );
  $handler->display->display_options['style_options']['default'] = 'php_1';
  $handler->display->display_options['style_options']['info'] = array(
    'php_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_host' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_5' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_6' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'domain_blocked_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_11' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_8' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_7' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_12' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_9' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_10' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['grouped_relationships'] = array(
    'base' => 0,
    'field_domain_relays_target_id' => 0,
    'field_relay_target_site_target_id' => 0,
    'reverse_field_target_node' => 0,
    'reverse_field_target_domain_node' => 0,
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$total_active_connections = 0;
$total_blocked_relays = 0;
foreach($results as $val){

$total_active_connections = $total_active_connections + $val->views_php_14;
if($val->views_php_0 == "1.000000" || $val->views_php_1 == "1.000000" ){
$total_blocked_relays = $total_blocked_relays +1;
}

}
echo "<li>Total domains : " . count($results) . "</li>";
echo "<li>Total blocked domains : " . number_format($total_blocked_relays) . "</li>";
echo "<li>Overall Active Connections : " . number_format($total_active_connections) . "</li>";
?>


';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_sites_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  /* Field: Content: Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Requests';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '//$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
//$data_rrd = rrd_fetch($file, $opts);
$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][360];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'IP Blocking';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'DNS Blocking';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
$ret = dprint_r($relay,true);
return $ret;';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
echo value;
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Traffic Graph';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
$directory = "sites/default/files" . "/{$host}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $host . " nginx requests",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');   
  $output = "<em>No Data Available</em>";
}
return $output;';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print $value;
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Health Graph ';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
$directory = "sites/default/files" . "/{$ip}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current-health.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $ip . " IP Block Monitoring",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');    
  $output = "<em>No Data Available</em>";
}

return $output;';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if ($row->php_4 =="1") {
return "Blocked";
}
else {
return "Accessible";
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
//print render(drupal_get_form(\'mitigate_action_form\'));
echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_domain_relays_target_id';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'domain' => 'domain',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Relay type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['filters']['field_resource_type_tid']['value'] = array(
    4 => '4',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Relay type';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Distribution Type (field_distribution_type) */
  $handler->display->display_options['filters']['field_distribution_type_tid']['id'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['table'] = 'field_data_field_distribution_type';
  $handler->display->display_options['filters']['field_distribution_type_tid']['field'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['filters']['field_distribution_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['operator_id'] = 'field_distribution_type_tid_op';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['label'] = 'Distribution Type';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['operator'] = 'field_distribution_type_tid_op';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['identifier'] = 'field_distribution_type_tid';
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_distribution_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_distribution_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distribution_type_tid']['vocabulary'] = 'distribution';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['id'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['table'] = 'field_data_field_relay_target_site';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['field'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['label'] = 'Relay_Target_Site';
  /* Relationship: DNS_Blocking_Event */
  $handler->display->display_options['relationships']['reverse_field_target_node']['id'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['field'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['ui_name'] = 'DNS_Blocking_Event';
  $handler->display->display_options['relationships']['reverse_field_target_node']['label'] = 'DNS_Blocking_Event';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['id'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['field'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['relationships']['reverse_field_target_domain_node']['label'] = 'Campain_Domain';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'IP Blocking';
  $handler->display->display_options['fields']['php_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
$domain = $row->title;
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/" . $domain . "/IPBlock-" . $ip . ".rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'DNS Blocking';
  $handler->display->display_options['fields']['php_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
$domain = $row->title;
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/" .$domain. "/DNSTamper.rrd";
//$options = array("AVERAGE", "--start", "-1h");
//$data_rrd = rrd_fetch($rrd_file, $options, count($options));
$data_rrd = rrd_lastupdate($rrd_file);
$ret = $data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][12];
//$ret = "<br/>" . dprint_r($data_rrd,true);
//$ret = dprint_r($relay,true);
return $ret;';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'if ($row->php_4 =="1") {
return "<b style=\'color:red;\'>Blocked</b>";
}
else {
return "<b style=\'color:green;\'>Accessible</b>";
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
//print render(drupal_get_form(\'mitigate_action_form\'));
echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Domain Nid';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'Relay Nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type_1']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  $handler->display->display_options['fields']['title_2']['exclude'] = TRUE;
  /* Field: Content: Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['fields']['nid_2']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_5']['id'] = 'title_5';
  $handler->display->display_options['fields']['title_5']['table'] = 'node';
  $handler->display->display_options['fields']['title_5']['field'] = 'title';
  $handler->display->display_options['fields']['title_5']['relationship'] = 'reverse_field_target_domain_node';
  $handler->display->display_options['fields']['title_5']['label'] = 'Campaign';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Relay Requests';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";

$total = 0;
if(file_exists($file)){
$opts = array ("AVERAGE", "-r", "26350", "-s", 1326904100);
$distrib_requests = rrd_fetch($file, $opts);
foreach ($distrib_requests["data"]["value"] as $key => $val){
  if(!is_nan($val)){
    $total = $total + floatval($val)*26350;
  }
}
}
return $total;

/*$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];*/';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo(number_format($value));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Active Connections';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_value'] = '//$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_connections-active.rrd";
//$data_rrd = rrd_fetch($file, $opts);
$data_rrd = rrd_lastupdate($file);
$ret = (int)$data_rrd[\'data\'][0];
//$ret = $data_rrd[\'data\'][360];
//$ret = "<br/>" . dprint_r($data_rrd,true);
return $ret;';
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Traffic Graph (Last 7 Days)';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$opts = array ( "AVERAGE", "--start", \'-1h\');
$relay = node_load($row->field_host);
$host = $relay->field_host[\'und\'][0][\'safe_value\'];
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/" . $host . "/nginx/nginx_requests.rrd";
$directory = "sites/default/files" . "/{$host}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $host . " nginx requests",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');   
  $output = "<em>No Data Available</em>";
}
return $output;';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print $value;
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Health Graph ';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/website.info/IPBlock-" . $ip . ".rrd";
$directory = "sites/default/files" . "/{$ip}/";
file_prepare_directory($directory, FILE_CREATE_DIRECTORY);
$image_file = $directory .\'/current-health.png\';
$options = array(
  "--start=" . (mktime() - 7*24*3600),
  "--end=" . mktime(),
  "DEF:value=" . $rrd_file . ":value:AVERAGE",
  "LINE1:value#FF0000:\\"Value\\"",
  "--title=" . $ip . " IP Block Monitoring",
  );
$rc = rrd_graph($image_file, $options);
$image[\'path\'] = $image_file;
$output = theme(\'image\', $image);
if (!$rc) {
//      drupal_set_message(rrd_error(), \'error\');    
  $output = "<em>No Data Available</em>";
}

return $output;';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: DNS Mitigation */
  $handler->display->display_options['fields']['domain_blocked_link']['id'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['domain_blocked_link']['field'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['label'] = 'Report As Blocked';
  $handler->display->display_options['fields']['domain_blocked_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['domain_blocked_link']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_11']['id'] = 'php_11';
  $handler->display->display_options['fields']['php_11']['table'] = 'views';
  $handler->display->display_options['fields']['php_11']['field'] = 'php';
  $handler->display->display_options['fields']['php_11']['label'] = 'Mark as Blocked (Domain)';
  $handler->display->display_options['fields']['php_11']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_11']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_11']['php_output'] = '<?php global $base_url; ?>
<a href="<?php echo $base_url; ?>/eform/submit/testing-mitigation-component?edit[field_testing_domain][und]=<?php echo $row->nid_1; ?>">Mark as blocked</a>';
  $handler->display->display_options['fields']['php_11']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_11']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Last Unresolved DNS Blocking Event';
  $handler->display->display_options['fields']['php_8']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = '$event_node = "";
$query = new EntityFieldQuery();
  $query->entityCondition("entity_type", "node")
        ->entityCondition("bundle", "event_dns_blocked")
        ->propertyCondition("status", 1)
        ->fieldCondition("field_target", "target_id", $row->nid_1);
  $result = $query->execute();

if(isset($result[\'node\'])){
  foreach($result[\'node\'] as $key => $val) {
    $node = node_load($val->nid);
    if($node->workflow == 13 || $node->workflow == 14 || $node->workflow == 15){
      $event_node =  $node->nid;
    }
  }
}
return $event_node ;';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
global $base_url;
if((int)$value > 0){
echo(\'<a href="\' . $base_url . \'/node/\' . $value . \'">Link</a>\'); 
}
?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'Mitigate DNS Blocking';
  $handler->display->display_options['fields']['php_7']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_value'] = 'global $base_url;
if((int)$row->php_8 > 0){
if ($row->php_4 =="1") {
return \'<a href="\' . $base_url . \'/remedy/provision/domain?edit[field_blocked_domain][und]=\' . $row->nid_1 . \'&edit[field_blocking_event][und]=\' . $row->php_8 . \'">Click Here</a>\';
}
else {
return \'<a href="/drupal/remedy/provision/domain?edit[field_blocked_domain][und]=\' . $row->nid_1 . \'&edit[field_blocking_event][und]=\' . $row->php_8. \'">Click Here</a>\';
}
}';
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_12']['id'] = 'php_12';
  $handler->display->display_options['fields']['php_12']['table'] = 'views';
  $handler->display->display_options['fields']['php_12']['field'] = 'php';
  $handler->display->display_options['fields']['php_12']['label'] = 'Mark as Blocked (IP)';
  $handler->display->display_options['fields']['php_12']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_12']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_12']['php_output'] = '<?php
global $base_url;
?>
<a href="<?php echo $base_url; ?>/eform/submit/test-ipaddress-block-mitigation?edit[field_relays][und]=<?php echo $row->nid; ?>">Mark as blocked</a>';
  $handler->display->display_options['fields']['php_12']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_12']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['label'] = 'Last Unresolved IP Blocking Event';
  $handler->display->display_options['fields']['php_9']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_9']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_9']['php_value'] = '$event_node = "";
$query = new EntityFieldQuery();
  $query->entityCondition("entity_type", "node")
        ->entityCondition("bundle", "event_ip_blocked")
        ->propertyCondition("status", 1)
        ->fieldCondition("field_target", "target_id", $row->nid);
  $result = $query->execute();
if(isset($result[\'node\'])){
  foreach($result[\'node\'] as $key => $val) {
    $node = node_load($val->nid);
    if($node->workflow == 13 || $node->workflow == 14 || $node->workflow == 15){
      $event_node =  $node->nid;
    }
  }
}
return $event_node ;';
  $handler->display->display_options['fields']['php_9']['php_output'] = '<?php
global $base_url;
if((int)$value > 0){
echo(\'<a href="\' . $base_url . \'/node/\' . $value . \'">Link</a>\'); 
}
?>';
  $handler->display->display_options['fields']['php_9']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_9']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_10']['id'] = 'php_10';
  $handler->display->display_options['fields']['php_10']['table'] = 'views';
  $handler->display->display_options['fields']['php_10']['field'] = 'php';
  $handler->display->display_options['fields']['php_10']['label'] = 'Mitigate IP Blocking';
  $handler->display->display_options['fields']['php_10']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_value'] = 'global $base_url;
if((int)$row->php_8 > 0){

if ($row->php_4 =="1") {
return \'<a href="\' . $base_url . \'/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_9 . \'">Click Here</a>\';
}
else {
return \'<a href="/drupal/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_9 . \'">Click Here</a>\';
}
}';
  $handler->display->display_options['fields']['php_10']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php_10']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_10']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = '';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['path'] = 'dashboard';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Dashboard';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['dashboard_overview_'] = $view;

  return $export;
}
