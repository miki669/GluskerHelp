﻿//Напишите выражение (то есть фрагмент программы, что может стоять справа от знака присваивания), которое пере-
//водит число из двоичной в восьмеричную систему счисления. Количество цифр в исходном числе – не более 5, исходное
//число и результат записывается в 10-ой системе счисления так, что каждый разряд заполнен соответствующей двоичной
//(восьмеричной) цифрой.

program practica1;
var a,b:integer;
begin
  writeln('input b');
  readln(b);
  a:= (b mod 10 + b mod 100 div 10 * 2 + b mod 1000 div 100 * 2 * 2 + (b mod 10000 div 1000 + b div 10000 * 2) * 10);
  writeln('Answer: ', a);
end.