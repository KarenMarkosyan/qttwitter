#ifndef HTTP_H
#define HTTP_H
//
#include <QObject>
//
class Http  :public QObject
{
Q_OBJECT
public:
	Http();

public slots:
	void httpCall(QString);
/*signals:
	void outputOfHttpCall(QString);
*/
	
};

namespace Backend {
    class HttpBackend: public Http {};
}
#endif
