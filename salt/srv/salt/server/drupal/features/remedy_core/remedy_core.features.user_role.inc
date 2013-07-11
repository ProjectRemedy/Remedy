<?php
/**
 * @file
 * remedy_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function remedy_core_user_default_roles() {
  $roles = array();

  // Exported role: Relay administrator.
  $roles['Relay administrator'] = array(
    'name' => 'Relay administrator',
    'weight' => 3,
  );

  // Exported role: anonymous user.
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
    'weight' => 0,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 1,
  );

  return $roles;
}
