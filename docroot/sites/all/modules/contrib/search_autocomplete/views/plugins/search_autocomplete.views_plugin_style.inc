<?php
/**
 * @file
 * Implements views_plugin_style for search_autocomplete
 */

/**
 * Implements views_plugin_style
 */
class search_autocomplete_views_plugin_style extends views_plugin_style {
  /**
   * Implements views_plugin_style::option_definition
   */
  function option_definition() {
    $options = parent::option_definition();
      $options['group_by'] = array('default' => FALSE);
      $options['input_label'] = array('default' => FALSE);
      $options['input_link'] = array('default' => FALSE);
      $options['output_fields'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {

    // Get all views fields.
    $all_view_fields = $this->display->handler->get_field_labels();
  	// Build the value option.
    $group_fields = $all_view_fields;
    array_unshift($group_fields, "- no grouping -");
    $form['group_by'] = array(
      '#title'          => t('Group fields by'),
      '#type'           => 'select',
      '#description'    => (empty($all_view_fields) ? '<b>' . t('Warning') . ': </b> ' . t('Requires at least one field in the view.') . '<br/>' : '')
                            . t("You may want to group fields together."),
      '#default_value'  => $this->options['group_by'],
      '#disabled'       => empty($all_view_fields),
      '#required'       => TRUE,
      '#options'        => $group_fields,
    );
    
    $form['input_label'] = array(
      '#title'          => t('Input Label'),
      '#type'           => 'select',
      '#description'    => (empty($all_view_fields) ? '<b>' . t('Warning') . ': </b> ' . t('Requires at least one field in the view.') . '<br/>' : '')
                            . t('Select the autocompletion input value. If the autocompletion settings are set to auto-submit, this value will be submitted as the suggestion is selected.'),
      '#default_value'  => $this->options['input_label'],
      '#disabled'       => empty($all_view_fields),
      '#required'       => TRUE,
      '#options'        => $all_view_fields,
    );

    // Build the link option.
    $form['input_link'] = array(
      '#title'          => t('Input Link'),
      '#type'           => 'select',
      '#description'    => (empty($all_view_fields) ? '<b>' . t('Warning') . ': </b> ' . t('Requires at least one field in the view.') . '<br/>' : '')
                            . t('Select the autocompletion input link. If the autocompletion settings are set to auto-redirect, this link is where the user will be redirected as the suggestion is selected.'),
      '#default_value'  => $this->options['input_link'],
      '#disabled'       => empty($all_view_fields),
      '#required'       => TRUE,
      '#options'        => $all_view_fields,
    );
    
    // Build the link option.
    $form['output_fields'] = array(
      '#title'          => t('Output Fields'),
      '#type'           => 'select',
      '#description'    => (empty($all_view_fields) ? '<b>' . t('Warning') . ': </b> ' . t('Requires at least one field in the view.') . '<br/>' : '')
                            . t("Select the autocompletion output values. Thoses fields are the one that will show in the autocompletion popup suggestion list. This may be, the username and picture for instance, or the node title and it's author."),
      '#default_value'  => $this->options['output_fields'],
      '#disabled'       => empty($all_view_fields),
      '#required'       => TRUE,
      '#multiple'       => TRUE, 
      '#options'        => $all_view_fields,
    );
  }

  /**
   * Implements view_style_plugin::render().
   *
   * This methods renders the JSON Autocompletion view style.
   */
  function render() {
    $view = $this->view;
    $options = $this->options;

    $rows = array();
    foreach ($view->result as $count => $row) {
      $view->row_index = $count;
      $rows[] = _search_autocomplete_render_fields($view, $row);
    }
    unset($view->row_index);

    $ret = theme($this->theme_functions(), array('view' => $view, 'options' => $options, 'rows' => $rows));
    return $ret;
  }
}
