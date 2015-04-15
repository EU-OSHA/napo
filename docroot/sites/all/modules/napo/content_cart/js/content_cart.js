(function($){

    Drupal.behaviors.content_cart_check_submit = {
        attach: function (context, settings) {
            $('input.content_cart_checkbox', context).once('content_cart_check_submit', function () {
                var id = $(this).val();
                if (typeof id != 'undefined') {
                    var operation = 'remove';
                    if (!$(this).is('checked')) {
                        operation = 'add';
                    }
                    var ajax_settings = {};
                    ajax_settings.url = '/content_cart/ajax/submit/' + operation + '/' + id;
                    ajax_settings.event = 'click';
                    var base = 'input.content_cart_checkbox';
                    Drupal.ajax['content_cart_submit'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });
        }
    };
})(jQuery);

