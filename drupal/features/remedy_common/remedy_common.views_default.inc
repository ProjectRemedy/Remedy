<?php
/**
 * @file
 * remedy_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function remedy_common_views_default_views() {
  $export = array();

  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table_grouped_relationship';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'php_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
    'field_resource_type_1' => 'field_resource_type_1',
    'title_2' => 'title_2',
    'field_host' => 'field_host',
    'field_resource_type' => 'field_resource_type',
    'php' => 'php',
    'php_4' => 'php_4',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_1' => 'php_1',
  );
  $handler->display->display_options['style_options']['default'] = 'php_1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
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
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_4' => array(
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
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['grouped_relationships'] = array(
    'base' => 0,
    'field_domain_relays_target_id' => 0,
    'field_relay_sites_target_id' => 0,
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$opts = array ( "AVERAGE", "--start", \'-1h\');
$overall = 0;
foreach($results as $key => $val){
$data_rrd = rrd_lastupdate("/opt/collectd/var/lib/collectd/rrd/" . $val->field_field_host[0]["raw"]["safe_value"] . "/nginx/nginx_requests.rrd");
$overall = $overall + (int)$data_rrd[\'data\'][0];
}
//echo "<h4>Requests</h4>" . $overall;
?>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['id'] = 'field_relay_sites_target_id';
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['table'] = 'field_data_field_relay_sites';
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['field'] = 'field_relay_sites_target_id';
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['label'] = 'Relay_Sites';
  $handler->display->display_options['relationships']['field_relay_sites_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_sites_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Content: Internal Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['label'] = 'Host';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_host']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_host']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_host']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_host']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_host']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_host']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_host']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_host']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_host']['field_api_classes'] = 0;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_resource_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Requests';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_4']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_4']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/".$node->title.".info/IPBlock-" . $ip . ".rrd";
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
  $handler->display->display_options['fields']['php_5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_5']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_5']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/".$node->title.".info/IPBlock-" . $ip . ".rrd";
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
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_2']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/$/IPBlock-" . $ip . ".rrd";
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
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = '';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
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
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['field_resource_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['error_message'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['id'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['table'] = 'field_data_field_domain_relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['field'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['label'] = 'Domain_Relays';
  $handler->display->display_options['relationships']['field_domain_relays_target_id']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['id'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['table'] = 'field_data_field_relay_target_site';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['field'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['label'] = 'Relay_Target_Site';
  $handler->display->display_options['relationships']['field_relay_target_site_target_id']['required'] = 0;
  /* Relationship: DNS_Blocking_Event */
  $handler->display->display_options['relationships']['reverse_field_target_node']['id'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['field'] = 'reverse_field_target_node';
  $handler->display->display_options['relationships']['reverse_field_target_node']['ui_name'] = 'DNS_Blocking_Event';
  $handler->display->display_options['relationships']['reverse_field_target_node']['label'] = 'DNS_Blocking_Event';
  $handler->display->display_options['relationships']['reverse_field_target_node']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Domain Nid';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Relay';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['nid']['label'] = 'Relay Nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type_1']['id'] = 'field_resource_type_1';
  $handler->display->display_options['fields']['field_resource_type_1']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type_1']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_resource_type_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_resource_type_1']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_relay_target_site_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Site';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Content: Internal Host */
  $handler->display->display_options['fields']['field_host']['id'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['table'] = 'field_data_field_host';
  $handler->display->display_options['fields']['field_host']['field'] = 'field_host';
  $handler->display->display_options['fields']['field_host']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_host']['label'] = 'Host';
  $handler->display->display_options['fields']['field_host']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_host']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_host']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_host']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_host']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_host']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_host']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_host']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_host']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_host']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_host']['field_api_classes'] = 0;
  /* Field: Content: Relay type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['relationship'] = 'field_domain_relays_target_id';
  $handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_resource_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_resource_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_resource_type']['field_api_classes'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Relay Requests';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Relay Active Connections';
  $handler->display->display_options['fields']['php_6']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_6']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_6']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_6']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_6']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_6']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_6']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_6']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_6']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'IP Blocking';
  $handler->display->display_options['fields']['php_4']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_4']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_4']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_4']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_4']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_4']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_4']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_4']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_4']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_5']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_5']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_5']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_5']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_5']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_5']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_5']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_5']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_5']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Traffic Graph';
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_2']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_3']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$relay = node_load($row->field_host);
$ip = $relay->field_ip_address[\'und\'][0][\'safe_value\'];
// Later iterate over various probes to see if the IP matches.
$rrd_file = "/opt/collectd/var/lib/collectd/rrd/remedy-prober-cn1/$node->title/IPBlock-" . $ip . ".rrd";
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
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
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
  /* Field: Node: DNS Mitigation */
  $handler->display->display_options['fields']['domain_blocked_link']['id'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['domain_blocked_link']['field'] = 'domain_blocked_link';
  $handler->display->display_options['fields']['domain_blocked_link']['label'] = 'Report As Blocked';
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['external'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['alter']['html'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['domain_blocked_link']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['domain_blocked_link']['hide_empty'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['empty_zero'] = 0;
  $handler->display->display_options['fields']['domain_blocked_link']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['domain_blocked_link']['rules_link'] = array(
    'rules_link_parameters' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Last Unresolved DNS Blocking Event';
  $handler->display->display_options['fields']['php_8']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_8']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_8']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_8']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_8']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_8']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_8']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_8']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_8']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_7']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_7']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_7']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_7']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_7']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_7']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_7']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_7']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_7']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_value'] = 'if((int)$row->php_8 > 0){
if ($row->php_4 =="1") {
return \'<a href="/drupal/remedy/provision/domain?edit[field_blocked_domain][und]=\' . $row->nid_1 . \'&edit[field_blocking_event][und]=\' . $row->php_8 . \'">Click Here</a>\';
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
  $handler->display->display_options['fields']['php_9']['id'] = 'php_9';
  $handler->display->display_options['fields']['php_9']['table'] = 'views';
  $handler->display->display_options['fields']['php_9']['field'] = 'php';
  $handler->display->display_options['fields']['php_9']['label'] = 'Last Unresolved IP Blocking Event';
  $handler->display->display_options['fields']['php_9']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_9']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_9']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_9']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_9']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_9']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_9']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_9']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_9']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['fields']['php_10']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_10']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_10']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_10']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_10']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php_10']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_10']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_10']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_10']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_10']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_10']['php_value'] = 'if((int)$row->php_8 > 0){
if ($row->php_4 =="1") {
return \'<a href="/drupal/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_10 . \'">Click Here</a>\';
}
else {
return \'<a href="/drupal/remedy/provision/ipaddress?edit[field_blocked_relay][und]=\' . $row->nid . \'&edit[field_blocking_event][und]=\' . $row->php_10 . \'">Click Here</a>\';
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
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = '';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
  $handler->display->display_options['path'] = 'dashboard';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Dashboard';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['dashboard'] = $view;

  $view = new view;
  $view->name = 'dns_mitigation_logged_tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'DNS Mitigation Logged Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'DNS Blocking Mitigation Tasks ';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<h4>DNS Blocking Mitigation Tasks</h4>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_dns_blocking_event_target_id']['id'] = 'field_dns_blocking_event_target_id';
  $handler->display->display_options['relationships']['field_dns_blocking_event_target_id']['table'] = 'field_data_field_dns_blocking_event';
  $handler->display->display_options['relationships']['field_dns_blocking_event_target_id']['field'] = 'field_dns_blocking_event_target_id';
  $handler->display->display_options['relationships']['field_dns_blocking_event_target_id']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_dns_blocking_event_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'event_dns_blocked',
  );
  $export['dns_mitigation_logged_tasks'] = $view;

  $view = new view;
  $view->name = 'logged_tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'IP Mitigation Logged Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'IP Address Blocking Mitigation Tasks';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ip_address_blocking_event_target_id']['id'] = 'field_ip_address_blocking_event_target_id';
  $handler->display->display_options['relationships']['field_ip_address_blocking_event_target_id']['table'] = 'field_data_field_ip_address_blocking_event';
  $handler->display->display_options['relationships']['field_ip_address_blocking_event_target_id']['field'] = 'field_ip_address_blocking_event_target_id';
  $handler->display->display_options['relationships']['field_ip_address_blocking_event_target_id']['required'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_ip_address_blocking_event_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'event_ip_blocked',
  );
  $export['logged_tasks'] = $view;

  return $export;
}
