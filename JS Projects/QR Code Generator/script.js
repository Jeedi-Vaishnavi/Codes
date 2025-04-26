let qrtext=document.getElementById("qrtext");
let qrimgbox=document.getElementById("qrimgbox");
let qrimg=document.getElementById("qrimg");
function qrgenerator()
{
 qrimg.src="https://api.qrserver.com/v1/create-qr-code/?size=150x&data=" + qrtext.value;
 }