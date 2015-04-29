<?php
/**
 * @file
 * Provide the HTML output of the Video.js video player.
 */
/**include("/home/sorin/napo/docroot/sites/all/libraries/video-js/video-js.css");*/
$attrs = '';
if (!empty($autoplay)) {
  $attrs .= ' autoplay="autoplay"';
}
if (!empty($poster)) {
  $attrs .= ' poster="'. check_plain($poster) .'"';
}

if (!empty($items)): ?>
<video id="<?php print $player_id; ?>-video" data-setup="{}" class="video-js vjs-default-skin"
       width="<?php print($width) ?>" height="<?php print($height) ?>"
       controls="controls" preload="auto"
       <?php echo $attrs; ?>
       >
<?php $ok=false; 
foreach ($items as $item): 
	if (strcmp ( $item['videotype'] ,"video/mp4") == 0):?>
		<source src="<?php print check_plain(file_create_url($item['uri'])) ?>" type="<?php print check_plain($item['videotype']) ?>" />
		<?php $ok=true; break; 
	endif;?>
<?php endforeach; 
if($ok == false):
?>
	<source src="<?php print check_plain(file_create_url($items[0]['uri'])) ?>" type="<?php print check_plain($items[0]['videotype']) ?>" />
<?php endif;?>		
</video>
<?php endif;
