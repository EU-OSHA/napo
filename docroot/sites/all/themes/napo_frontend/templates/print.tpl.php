<?php

/**
 * @file
 * Default theme implementation to display a printer-friendly version page.
 *
 * This file is akin to Drupal's page.tpl.php template. The contents being
 * displayed are all included in the $content variable, while the rest of the
 * template focuses on positioning and theming the other page elements.
 *
 * All the variables available in the page.tpl.php template should also be
 * available in this template. In addition to those, the following variables
 * defined by the print module(s) are available:
 *
 * Arguments to the theme call:
 * - $node: The node object. For node content, this is a normal node object.
 *   For system-generated pages, this contains usually only the title, path
 *   and content elements.
 * - $format: The output format being used ('html' for the Web version, 'mail'
 *   for the send by email, 'pdf' for the PDF version, etc.).
 * - $expand_css: TRUE if the CSS used in the file should be provided as text
 *   instead of a list of @include directives.
 * - $message: The message included in the send by email version with the
 *   text provided by the sender of the email.
 *
 * Variables created in the preprocess stage:
 * - $print_logo: the image tag with the configured logo image.
 * - $content: the rendered HTML of the node content.
 * - $scripts: the HTML used to include the JavaScript files in the page head.
 * - $footer_scripts: the HTML  to include the JavaScript files in the page
 *   footer.
 * - $sourceurl_enabled: TRUE if the source URL infromation should be
 *   displayed.
 * - $url: absolute URL of the original source page.
 * - $source_url: absolute URL of the original source page, either as an alias
 *   or as a system path, as configured by the user.
 * - $cid: comment ID of the node being displayed.
 * - $print_title: the title of the page.
 * - $head: HTML contents of the head tag, provided by drupal_get_html_head().
 * - $robots_meta: meta tag with the configured robots directives.
 * - $css: the syle tags contaning the list of include directives or the full
 *   text of the files for inline CSS use.
 * - $sendtoprinter: depending on configuration, this is the script tag
 *   including the JavaScript to send the page to the printer and to close the
 *   window afterwards.
 *
 * print[--format][--node--content-type[--nodeid]].tpl.php
 *
 * The following suggestions can be used:
 * 1. print--format--node--content-type--nodeid.tpl.php
 * 2. print--format--node--content-type.tpl.php
 * 3. print--format.tpl.php
 * 4. print--node--content-type--nodeid.tpl.php
 * 5. print--node--content-type.tpl.php
 * 6. print.tpl.php
 *
 * Where format is the ouput format being used, content-type is the node's
 * content type and nodeid is the node's identifier (nid).
 *
 * @see print_preprocess_print()
 * @see theme_print_published
 * @see theme_print_breadcrumb
 * @see theme_print_footer
 * @see theme_print_sourceurl
 * @see theme_print_url_list
 * @see page.tpl.php
 * @ingroup print
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>">
  <head>
    <?php 
    global $language;
    print $head; 
    ?>
    <base href='<?php print $url ?>' />
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title><?php print $print_title; ?></title>
    <?php print $scripts; ?>
    <?php if (isset($sendtoprinter)) print $sendtoprinter; ?>
    <?php print $robots_meta; ?>
    <?php if (theme_get_setting('toggle_favicon')): ?>
      <link rel='shortcut icon' href='<?php print theme_get_setting('favicon') ?>' type='image/x-icon' />
    <?php endif; ?>
    <style>

      html{
        font-family: DejaVu Sans !important;
      }

      .page-header{
        font-weight: 300!important;
        font-family: 'Open Sans', sans-serif!important;
        font-size: 2.6em;
        padding-left: 0;
        margin-left: -10px;
        padding-top: 0px;
        padding-bottom: 0px;
      }

      a{
        text-decoration: none;
        border-bottom: 1px solid #1f3695;
        color: #1f3695 !important;
      }

      .print-footnote {
          visibility: hidden;
          display: none;
      }

      .header-title{
        color:#1f3797 !important;
        text-align: center;
        font-size: 18pt;
        font-weight: bold;
      }

      .print-title{
        color:#1f3695 !important;
        padding-top: 0!important;
        padding-left: 23px;
      }

      .print-content h1{
        display: none !important;
        visibility: hidden !important;
        background:none;
        font-size: 20pt !important;
      }

      .print-content h2{
        font-size: 16pt !important;
      }

      .print-content h3{
        color:#1f3695 !important;
        font-size: 14pt !important;
        margin-bottom: 0 !important;
        padding-bottom: 0 !important;
      }

      .print-content h4{
        font-size: 12pt;
        margin-bottom: 0 !important;
        padding-bottom: 0 !important;
      }

      .print-content .acordion-content-text{
        color:#333333 !important;
        padding-top: 0 !important;
        margin-top: 0 !important;
      }

      .print-content{
        font-size: 10pt;
      }
      
      #footer a{
        color: #1f3695;
        font-size: 10pt;
        bottom: 40px;
        font-style: normal;
      }

      #footer:after { 
        content: counter(page); 
        font-size: 22px; 
        position: absolute; 
        right: 05px; 
        top: -10px; 
      }

    </style>
    <?php print $css; ?>

  </head>
  <?php $headerpath = base_path() . path_to_theme() .'/logo.png' ; ?>
  <header style="position: fixed; top:-30px;">
    <div class="header-title">Napo for teachers</div>
    <?php print '<img style="width:342;height:74px;" src="' . $headerpath . '">'; ?>
    <div class="print-title"><?php print $print_title; ?></div>
  </header>
  <body style="padding-top:180px;">
    <?php if (!empty($message)): ?>
      <div class="print-message"><?php print $message; ?></div><p />
    <?php endif; ?>
    <div class="print-content"><?php print $content; ?></div>
  </body>
  <div id="footer" style="position: fixed;bottom: 10px; left: 10px; width:100%;">
    <a href="https://napofilm.net">https://napofilm.net</a>
  </div>
</html>
