let h3=document.querySelector("h3");
let gameseq=[];
let userseq=[];
let btns=["blue","green","orange ","voilet"]
let started=false;
let level=0;
document.addEventListener("keypress",function()
{
    h3.innerText="game starte";
  if(started==false)
  {
  //console.log("game started now");
  started=true;
}
levelup();
});
function levelup()
{
    userseq=[];
level++;
h3.innerText=`level ${level}`;
let randIdx=Math.floor(Math.random() *3);
let randclr=btns[randIdx];
let randBtn=document.querySelector(`#${randclr}`);

console.log(gameseq);
gameflash(randBtn);
gameseq.push(randclr);
}
function gameflash(btn)
{
    btn.classList.add("flash");
    setTimeout(function(){
        btn.classList.remove("flash");
    },550);
}
function checkans(idx)
{
 //let idx=level-1;
 if(userseq[idx]==gameseq[idx]){
    if(userseq.length==gameseq.length){
        setTimeout(levelup(),1000);
    }
}
 else{
    h3.innerText=`Game over! Your score was ${level} press any key to start again`;
    document.querySelector("body").style.backgroundColor="red";
    setTimeout(function()
    {
document.querySelector("body").style.backgroundColor="white";
    },1000);
    reset();
}
}
function userflash(btn) 
{
    btn.classList.add("userflash");
    setTimeout(()=>{
        btn.classList.remove("userflash");
    },250);
   userseq.push(btn.getAttribute("id"));
    checkans(userseq.length-1);
} 
/*function btnpress()
{
    let btn=this;
    userflash(btn);
    usercolor=btn.getAttribute("id");
    userseq.push(usercolor);
    checkans(userseq.length-1); 
}*/
let allbtns=document.querySelectorAll(".btn");
for(btn of allbtns)
{
    btn.addEventListener("click",function()
    {
        userflash(this);
    });

}
function reset()
{
    started=0;
    gameseq=[];
    userseq=[];
     level=0; 
}
 