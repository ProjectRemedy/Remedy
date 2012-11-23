<?php
/**
 * @file
 * remedy_common.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function remedy_common_user_default_roles() {
  $roles = array();

  // Exported role: Relay administrator.
  $roles['Relay administrator'] = array(
    'name' => 'Relay administrator',
    'weight' => '3',
  );

  return $roles;
}
