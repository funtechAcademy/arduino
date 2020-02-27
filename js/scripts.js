console.log("js cargado!");





//Set your href attribute as href="javascript:delay('URL')" and JavaScript:

function delay (URL) {
    setTimeout( function() { window.location = URL }, 2000 );
}




//If you want to delay every link on your page, you can do it with jQuery like this

// $(function(){
//     $("a").click(function(evt){
//         var link = $(this).attr("href");
//         setTimeout(function() {
//             window.location.href = link;
//         }, 500);
//     });
// });

// var dismiss = window.addEventListener('load', function(){
//     document.getElementById("pageloader").classList.add("dimissloader");
//     this.console.log("hola");
// });

setTimeout(() => {
    document.getElementById("pageloader").classList.add("dimissloader");
    console.log("holamundo");
}, 1000);