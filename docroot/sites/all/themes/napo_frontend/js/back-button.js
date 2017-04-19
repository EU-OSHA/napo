jQuery(document).ready(function() {
    var back_button = jQuery("#napo_back_button");
    if(!back_button){
        alert('No back button');
        return;
    }
    var type = back_button.attr("rel");
    var referrer = document.referrer;

    switch(type) {
        case 'napo_video':
            if(napoReferrerSearch()){
                back_button.html(Drupal.t("Back to search results"));
                back_button.attr("href", referrer);
            }else{
                back_button.html(Drupal.t("Back to " + breadcrumbLastLink().text()));
                back_button.attr("href",breadcrumbLastLink().attr("href"));
            }
            break;
        case 'napo_album':
            if(napoReferrerSearch()){
                back_button.html(Drupal.t("Back to search results"));
                back_button.attr("href", referrer);
            }else{
                return;
            }
            break;
        case 'lesson':
            if(napoReferrerSearch()){
                back_button.html(Drupal.t("Back to search results"));
                back_button.attr("href", referrer);
            }else{
                back_button.html(Drupal.t("Back to " + breadcrumbLastLink().text()));
                back_button.attr("href",breadcrumbLastLink().attr("href"));
            }
            break;
        default:
            return;
            break;
    }
});

function breadcrumbLastLink(){
    return jQuery('.breadcrumb > span > a').last();
}

function napoReferrer(){
    if(document.referrer.indexOf(document.location.hostname)!=-1){
        return true;
    }
    return false;
}

function napoReferrerSearch(){
    if(napoReferrer() && document.referrer.indexOf('search')!=-1){
        return true;
    }
    return false;
}
