void eval(expression e)
{
   //assume the last token of e is '#'
   //a function next token
   Stack<Token> stack;
   for(Token x = NextToken(e); x != '#'; x = NextToken(e))
   {
      if(x is an operand) stack.Push(x);
      else{
         //remove the correct number of operands from stack
         //perform the evaluation
         //push the result back to stack
      }
   }

}