import 'package:flutter/material.dart';

void main() {
runApp(MyHomePage());
}

class MyHomePage extends StatelessWidget{
Widget build(BuildContext context){
	return MaterialApp(
	home: Center(
		child:Column(children:[
        Text('Hello World'),
         Text('from Aman'),
        
        ])
	),
	);
}
}
