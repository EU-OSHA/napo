<?php

/**
 * Test osha_homepage.module functionality.
 */
class FrontPageTest extends OshaWebTestCase {

  /**
   * Test JS/CSS inclusion.
   */
  public function testPreprocessNodeHook() {
    $this->drupalGet('');
    $this->assertRaw('jssor.slider.mini.js');
    $this->assertRaw('jssor.css');
  }
}
