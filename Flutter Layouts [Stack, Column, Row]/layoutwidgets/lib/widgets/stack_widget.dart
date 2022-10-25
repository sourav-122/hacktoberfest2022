import 'package:flutter/material.dart';

class StackWidget extends StatelessWidget {
  Widget build(BuildContext context) {
    final screenSize = MediaQuery.of(context).size;
    final screenHeight = screenSize.height;
    final screenWidth = screenSize.width;

    return SafeArea(
      child: Scaffold(
        body: SampleCode(screenHeight: screenHeight, screenWidth: screenWidth),
        // body: Text('Hello world'),
      ),
    );
  }
}

Widget SampleCode({var screenHeight, var screenWidth}) {
  final imageUrl = 'https://randomuser.me/api/portraits/men/32.jpg';

  return Stack(
    clipBehavior: Clip.none,
    alignment: Alignment.bottomCenter,
    children: [
      Container(
        height: screenHeight * 0.2,
        width: screenWidth,
        color: Colors.blue[900],
      ),
      Positioned(
        bottom: -screenWidth * 0.15,
        child: Container(
          height: screenHeight * 0.15,
          width: screenWidth * 0.30,
          decoration: BoxDecoration(
            color: Colors.red,
            borderRadius: BorderRadius.circular(screenWidth * 0.15),
            image: DecorationImage(
              image: NetworkImage(imageUrl),
            ),
          ),
        ),
      ),
    ],
  );
}
