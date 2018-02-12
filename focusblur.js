// Fig. 13.8: focusblur.js
// Demonstrating the focus and blur events. 

var helpText;

// initialize helpTextDiv and register event handlers
function init()
{
   helpText = document.getElementById( "helpText" );
   helpText.addEventListener("blur", abc, false);
   
   
   
} // end function init

// utility function to help register events
function abc()
{
   helpText = document.getElementById( "helpText" );
   var	sv = helpText.value;
   var len = sv.length;
   var tmp = "";
   for (var i=0; i<len; i++)
   {
	   if(sv[i]=='&')
	   {tmp+="and";}
	else{tmp+=sv[i];}
   }
   
   helpText.value = tmp;
	
 helpText.innerHTML=tmp;
 
}
window.addEventListener( "load", init, false );

