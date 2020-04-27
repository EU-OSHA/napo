<?php
/**
 * Sort the view by a boolean, is this is a entity queue node or not.
 */
class entityqueue_handler_sort_in_queue extends views_handler_sort {
  function query() {
    $this->query->add_orderby(NULL, "(field_data_eq_node.delta IS NULL)", $this->options['order']);
  }
}
