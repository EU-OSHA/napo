(function($){
    Drupal.behaviors.content_cart_check_submit = {
        attach: function (context, settings) {
            // Bind event for views checkbox - refresh the cart block.
            $('input.content_cart_checkbox' , context).once('content_cart_check_submit', function () {
                var id = $(this).val();
                if (typeof id != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'content_cart/ajax/submit/' + id;
                    ajax_settings.event = 'click';
                    var base = 'input.content_cart_checkbox';
                    Drupal.ajax['content_cart_submit'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });

            $('.content-cart-add-to-cart-btn' , context).once('content_cart_check_submit', function () {
                var id = $(this).data('value');
                if (typeof id != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'content_cart/ajax/submit/' + id;
                    ajax_settings.event = 'click';
                    var base = 'input.content_cart_checkbox';
                    Drupal.ajax['content_cart_submit'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });

            // Bind event for remove link. Refresh cart block and cart view.
            $('.content_cart_remove', context).once('content_cart_remove_submit', function () {
                var id = $(this).data('value');
                var view = $(this).data('view');
                if (typeof id != 'undefined' && typeof view != 'undefined') {
                    var ajax_settings = {};
                    ajax_settings.url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'content_cart/ajax/submit/' + id + '/remove/' + view;
                    ajax_settings.event = 'click';
                    var base = '.content_cart_remove';
                    Drupal.ajax['content_cart_remove'] = new Drupal.ajax(base, this, ajax_settings);
                }
            });
        }
    };

    $.fn.content_cart_toggle_button = function() {
        if (this.hasClass('node_in_content_cart')) {
            this.removeClass('node_in_content_cart');
            this.attr('title', this.data('addtitle'));
            if(this.data('outofcart')){
                $.bootstrapGrowl(this.data('outofcart'), {type:'success', allow_dismiss: true, width: 'auto'});
            }
        }
        else {
            this.addClass('node_in_content_cart');
            this.attr('title', this.data('removetitle'));
            if(this.data('incart')){
                $.bootstrapGrowl(this.data('incart'), {type:'success', allow_dismiss: true, width: 'auto'});
            }
        }
        return this;
    };

})(jQuery);
