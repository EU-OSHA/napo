<?php

class OshaTMGMTStatisticsTest extends OshaWebTestCase {

  public function testCount() {
    $data = array(
      'body' => array(
        '#label' => 'Body',
        0 => array(
          '#label' => 'Delta #0',
          'value' => array(
            '#label' => 'Body',
            '#text' => '<p id="tmgmt-1"> <table title="123456789ø"><tr><td><img title="1234567890" src="/sites/default/files/media-icons/default/video-x-generic.png" alt="0987654321" width="180" height="180"></td></tr></table> This is a sample text</p>',
            '#translate' => TRUE,
          ),
          'format' => array(
            '#label' => "",
            '#text' => "full_html",
            '#translate' => FALSE,
          )
        )
      ),
      'field_author' => array(
        '#label' => 'Autor',
        0 => array(
          '#label' => 'Delta #0',
          'value' => array(
            '#label' => 'Author',
            '#text' => 'EU-OSHA',
            '#translate' => TRUE,
          ),
          'format' => array(
            '#label' => "", '#text' => "", '#translate' => FALSE,
          )
        ),
      ),
      'title_field' => array(
        '#label' => 'Title',
        0 => array(
          '#label' => 'Delta #0',
          'value' => array(
            '#label' => "Title",
            '#text' => 'EUOSHA/AST/08/3 Personal Assistant to Director/Head of Unit (AST3), 3 years renewable contract',
            '#translate' => TRUE,
          ),
          'format' => array(
            '#label' => "", '#text' => "", '#translate' => FALSE,
          )
        )
      )
    );
    $count = 0;
    OshaTMGMTStatistics::count($data, $count);
    $this->assertEqual(137, $count);
  }
}
