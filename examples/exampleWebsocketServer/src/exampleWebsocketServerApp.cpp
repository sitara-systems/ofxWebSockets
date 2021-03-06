#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Websockets.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class exampleWebsocketServerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;

	std::shared_ptr<sitara::websocket::Server> mServer;
};

void exampleWebsocketServerApp::setup() {
	ci::app::setFrameRate(1);
	mServer = std::make_shared<sitara::websocket::Server>(9002);
	std::printf("Server running, will BLOCK until connection is made from Client...\n");
	mServer->run();
}

void exampleWebsocketServerApp::mouseDown( MouseEvent event )
{
}

void exampleWebsocketServerApp::update() {
}

void exampleWebsocketServerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( exampleWebsocketServerApp, RendererGl, [=](cinder::app::App::Settings* settings) { settings->setConsoleWindowEnabled(); })
