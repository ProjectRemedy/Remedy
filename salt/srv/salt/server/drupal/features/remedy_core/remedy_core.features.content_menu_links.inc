<?php
/**
 * @file
 * remedy_core.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function remedy_core_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: navigation:dashboard
  $menu_links['navigation:dashboard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: navigation:dashboard_advanced
  $menu_links['navigation:dashboard_advanced'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'dashboard_advanced',
    'router_path' => 'dashboard_advanced',
    'link_title' => 'Dashboard (advanced)',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');
  t('Dashboard (advanced)');


  return $menu_links;
}
