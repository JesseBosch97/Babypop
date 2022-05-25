#ifndef SESSION_H
#define SESSION_H


class Session
{
public:
   Session();

   void beginSession();
   void stopSession();

   int compressionAmount = 0;
   int ventilationAmount = 0;
   int sessionRepetitions = 0;

};

#endif // SESSION_H
