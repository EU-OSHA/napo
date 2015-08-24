jQuery('document').ready(function() {
    // Add a link to entity on every view row
    var link_url;
    jQuery('.view-search').find('.views-row').each(function(){
        jQuery(this).click(function(){
            link_url = jQuery(this).find('.field-name-node-link').find('a').attr('href');
            if(link_url){
                jQuery(location).attr('href', link_url);
            }
        });
    });
});
