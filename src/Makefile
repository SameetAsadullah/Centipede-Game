CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		 Board.o util.o game-release.o Centipede.o MoveableObject.o GameObject.o Position.o Game.o Segment.o MagicSeg.o LazySeg.o Mushroom.o Player.o Bullet.o Flea.o ScoreBoard.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game-release


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
