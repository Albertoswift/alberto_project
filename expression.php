<!DOCTYPE html>

<!-- Fig. 19.9: expression.php -->
<!-- Regular expressions. -->
<html>
   <head>
      <meta charset = "utf-8">
      <title>Regular expressions</title>
      <style type = "text/css">
         p { margin: 0; }
      </style>
   </head>
   <body>
      <?php
         $search = "Mississippi Alabama Texas Massachusetts Kansas";
         print( "<p>Test string is: '$search'</p>" );
        $vim;
         // call preg_match to search for pattern 'Now' in variable search
        
            
         // search for any word ending in 'ow'
         if ( preg_match( "/\b([a-zA-Z]*xas)\b/i", $search, $match ) )
		 { 	vim[0]= $match[ 1 ];
			print( "<p>Word found ending in 'xas': " .
		 $match[ 1 ] . "</p>" );
		 }
			   
		if ( preg_match( "/\b(K[a-zA-Z]*s)\b/i", $search, $match ) )
		{
			vim[1]= $match[ 1 ];
			print( "<p>Word found beginning with k and ending in s': " .
		$match[1] . "</p>" );
		}
            
         
		 if ( preg_match( "/\b(M[a-zA-Z]*s)\b/i", $search, $match ) )
		 {
			 vim[2]= $match[ 1 ];
			print( "<p>Word found beginning with M and ending in s': " .
		 $match[1] . "</p>" );
		 }
		 
		 if ( preg_match( "/\b([a-zA-Z]*a)\b/i", $search, $match ) )
		 {
			 vim[3]= $match[ 1 ];
			print( "<p>Word found ending in a: " .
		 $match[1] . "</p>" );
		 }
		 // search for any words beginning with 't'
		if ( preg_match( "/^\(M[a-zA-Z]\)", $search, $match ) )
		{
			vim[4]= $match[ 1 ];	
			print( "<p>Word found beginning with M at beginning of the string: " .
		$match[1] . "</p>" );
		}
		
	print("<p>$vim</p>");
        
     ?><!-- end PHP script -->
   </body>
</html>

