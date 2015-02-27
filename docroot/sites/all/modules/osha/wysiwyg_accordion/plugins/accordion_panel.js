(function ($) {
	Drupal.wysiwyg.plugins.accordion_panel = {
	  invoke: function(data,settings,instanceId) {
			Drupal.wysiwyg.instances[instanceId].insert('<div class="wysiwyg_accordion_panel">' + data.content + '</div>');
		},
	}
}(jQuery));
