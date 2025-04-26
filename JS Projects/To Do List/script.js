let text=document.getElementById("inputbox");
let btn=document.getElementsByClassName("add");
let listconatiner=document.getElementById("ullist");
function addtask()
{
    let li=document.createElement("li");
    li.innerHTML=text.value;
    let dlt=document.createElement("button");
    dlt.innerText="delete";
    dlt.classList.add("delete");
    ullist.appendChild(li);
    li.appendChild(dlt);
    text.value='';
}