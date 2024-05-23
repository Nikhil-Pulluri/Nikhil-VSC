function play(choice){
  const list = [`rock`,`paper`,`scissor`];

  let comp = list[Math.floor(Math.random()*3)];

  if(choice==comp) alert(`Tie`);

  else {
    if(comp==`rock` && choice==`paper` || comp==`paper` && choice==`scissor` || comp==`scissor`&&choice==`rock`) alert(`you win~ elli modda gudu \n ${comp}`);

    else if(choice==`rock` && comp==`paper` || choice==`paper` && comp==`scissor` || choice==`scissor`&&comp==`rock`) alert(`computer win \n${comp}`);
  }


}
