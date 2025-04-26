let btn=document.querySelector("button");
let ul=document.querySelector("ul");
let li=document.querySelectorAll("li");
let inp=document.querySelector("input");
btn.addEventListener("click",function(){
   let item=document.createElement("li");
   item.innerText=inp.value; 
   let dlt=document.createElement("button");
   dlt.innerText="delete";
   dlt.classList.add("delete");
   ul.appendChild(item);
   item.appendChild(dlt);
   inp.value="";
}); 
ul.addEventListener("click",function(event){
 if(event.target.nodeName=="Button")
 {
    let item2=event.target.parentElement;
    item2.remove();
 }
});
