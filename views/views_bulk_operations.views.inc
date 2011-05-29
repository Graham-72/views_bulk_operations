<?php

/**
 * Implements hook_views_data_alter().
 */
function views_bulk_operations_views_data_alter(&$data) {
  foreach (entity_get_info() as $entity_type => $info) {
    if (isset($data[$info['base table']])) {
      $data[$info['base table']]['views_bulk_operations'] = array(
        'title' => t('Bulk operations'),
        'help' => t('Execute bulk operations on the current object.'),
        'real field' => $info['entity keys']['id'],
        'field' => array(
          'handler' => 'views_bulk_operations_handler_field_operations',
          'click sortable' => FALSE,
        ),
      );
    }
  }
}