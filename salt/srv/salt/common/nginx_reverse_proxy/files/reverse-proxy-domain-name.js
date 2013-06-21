var _gaq = _gaq || [];
_gaq.push(['reverse-proxy-domain-name._setAccount', 'UA-xxxxxxx-xx']);
_gaq.push(['reverse-proxy-domain-name._trackPageview']);

if (typeof ga == 'undefined') {
  (function() {
    var ga = document.createElement('script'); ga.type =
'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' :
'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0];
s.parentNode.insertBefore(ga, s);
  })();
}
