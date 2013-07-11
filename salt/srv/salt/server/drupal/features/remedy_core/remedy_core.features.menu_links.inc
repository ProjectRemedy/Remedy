<?php
/**
 * @file
 * remedy_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function remedy_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation:node/add/distribution
  $menu_links['navigation:node/add/distribution'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/distribution',
    'router_path' => 'node/add/distribution',
    'link_title' => 'Distribution Campaign',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/domain
  $menu_links['navigation:node/add/domain'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/domain',
    'router_path' => 'node/add/domain',
    'link_title' => 'Domain',
    'options' => array(
      'attributes' => array(
        'title' => 'A given domain name, bound to one or several relays, used to access a destination web server',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/relay
  $menu_links['navigation:node/add/relay'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/relay',
    'router_path' => 'node/add/relay',
    'link_title' => 'Relay',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Distribution Campaign');
  t('Domain');
  t('Relay');


  return $menu_links;
}
