/**
* RNI API
* The ETSI MEC ISG MEC012 Radio Network Information API described using OpenAPI
*
* OpenAPI spec version: 1.1.1
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "pistache/router.h"
#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#include "smf-api-server.h"
#define PISTACHE_SERVER_MAX_PAYLOAD 32768

#ifdef __linux__
void sigHandler(int sig){
    switch(sig){
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
        case SIGHUP:
        default:
            break;
    }
    exit(0);
}

void setUpUnixSignals(std::vector<int> quitSignals) {
    sigset_t blocking_mask;
    sigemptyset(&blocking_mask);
    for (auto sig : quitSignals)
        sigaddset(&blocking_mask, sig);

    struct sigaction sa;
    sa.sa_handler = sigHandler;
    sa.sa_mask    = blocking_mask;
    sa.sa_flags   = 0;

    for (auto sig : quitSignals)
        sigaction(sig, &sa, nullptr);
}
#endif

using namespace oai::smf_server::api;

void SMFApiServer::init(size_t thr) {
	auto opts = Pistache::Http::Endpoint::options()
	.threads(thr);
    opts.flags(Pistache::Tcp::Options::ReuseAddr);
    opts.maxPayload(PISTACHE_SERVER_MAX_PAYLOAD);
	m_httpEndpoint->init(opts);
	m_individualPDUSessionHSMFApiImpl->init();
	m_individualSMContextApiImpl->init();
	m_pduSessionsCollectionApiImpl->init();
	m_smContextsCollectionApiImpl->init();

}
void SMFApiServer::start(){
	m_httpEndpoint->setHandler(m_router->handler());
	m_httpEndpoint->serve();

}
void SMFApiServer::shutdown(){
	m_httpEndpoint->shutdown();
}

/*
int main() {
#ifdef __linux__
    std::vector<int> sigs{SIGQUIT, SIGINT, SIGTERM, SIGHUP};
    setUpUnixSignals(sigs);
#endif

    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8080));
    SMFApiServer smfApiServer(addr);
    smfApiServer.init(2);
    smfApiServer.start();
    smfApiServer.shutdown();

}
*/
