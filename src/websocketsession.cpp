#include "../inc/websocketsession.h"
#include "../inc/msghandler.h"
#include "../inc/endpointwebsocket.h"


QThreadPool WebSocketSession::thread_pool;

WebSocketSession::WebSocketSession(QWebSocket *ws,
                                   EndPointWebSocket *endpoint) :
        mutex(),
        qrunnables_scheduled(0),
        ws(ws),
        endpoint(endpoint),
        user(),
        logged_in(false)
{
        connect(ws, &QWebSocket::textMessageReceived,
                this, &WebSocketSession::on_text_msg_rx);
        connect(ws, &QWebSocket::binaryMessageReceived,
                this, &WebSocketSession::on_bin_msg_rx);

        connect(this, &WebSocketSession::signal_bin_msg_tx,
                endpoint, &EndPointWebSocket::bin_msg_tx);
}

/* TODO use signals to call close and deleteLater
 * from the endpoint in main thread. */
WebSocketSession::~WebSocketSession()
{
        ws->close();
        ws->deleteLater();
}

void WebSocketSession::on_text_msg_rx(QString msg)
{
        QMutexLocker ml(&mutex);
        (void) msg;
}

void WebSocketSession::on_bin_msg_rx(QByteArray raw_msg)
{
        QMutexLocker ml(&mutex);
        MsgHandler *mh;

        try {
                mh = new MsgHandler(raw_msg, this);

                qrunnables_scheduled++;
                ml.unlock();

                mh->setAutoDelete(true);
                thread_pool.start(mh);
        } catch (...) {
                // TODO handle error
        }

        return;
}

void WebSocketSession::bin_msg_tx(QByteArray raw_msg)
{
        emit signal_bin_msg_tx(ws, raw_msg);
}
