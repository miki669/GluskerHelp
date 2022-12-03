program practica1;
var a,b:integer;
begin
  writeln('input b');
  readln(b);
  a:= (b mod 10 + b mod 100 div 10 * 2 + b mod 1000 div 100 * 2 * 2 + (b mod 10000 div 1000 + b div 10000 * 2) * 10);
  writeln('Answer: ', a);
end.