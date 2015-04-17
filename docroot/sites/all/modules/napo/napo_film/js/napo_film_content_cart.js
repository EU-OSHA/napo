(function($){
    Drupal.behaviors.napo_film_select_in_cart_submit = {
        attach: function (context, settings) {
            // Bind event for views checkbox - refresh the cart block.
            $('input.napo_film_select_in_cart', context).once('napo_film_select_in_cart_toggle', function () {
                var id = $(this).val();
                if (typeof id != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = '/napo_film/ajax/select_in_cart/' + id;
                    ajax_settings.event = 'change';
                    var base = 'input.napo_film_select_in_cart';
                    Drupal.ajax['napo_film_select_in_cart_toggle'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });
        }
    };
})(jQuery);

function napo_film_cart_select_all(item) {
    var $this = jQuery(item);
    var checkBoxes = jQuery(".napo_film_select_in_cart");
    if ($this.is(':checked')) {
        checkBoxes.prop("checked", true);
    }
    else {
        checkBoxes.prop("checked", false);
    }


}
