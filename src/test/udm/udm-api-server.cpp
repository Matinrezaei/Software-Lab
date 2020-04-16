/**
* Nudm_SDM
* Nudm Subscriber Data Management Service. � 2019, 3GPP Organizational Partners (ARIB, ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved. 
*
* The version of the OpenAPI document: 2.1.0.alpha-1
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

#include "AccessAndMobilitySubscriptionDataRetrievalApiImpl.h"
#include "GPSIToSUPITranslationApiImpl.h"
#include "GroupIdentifiersApiImpl.h"
#include "ProvidingAcknowledgementOfSteeringOfRoamingApiImpl.h"
#include "ProvidingAcknowledgementOfUEParametersUpdateApiImpl.h"
#include "RetrievalOfMultipleDataSetsApiImpl.h"
#include "RetrievalOfSharedDataApiImpl.h"
#include "SMFSelectionSubscriptionDataRetrievalApiImpl.h"
#include "SMSManagementSubscriptionDataRetrievalApiImpl.h"
#include "SMSSubscriptionDataRetrievalApiImpl.h"
#include "SessionManagementSubscriptionDataRetrievalApiImpl.h"
#include "SliceSelectionSubscriptionDataRetrievalApiImpl.h"
#include "SubscriptionCreationApiImpl.h"
#include "SubscriptionCreationForSharedDataApiImpl.h"
#include "SubscriptionDeletionApiImpl.h"
#include "SubscriptionDeletionForSharedDataApiImpl.h"
#include "SubscriptionModificationApiImpl.h"
#include "TraceConfigurationDataRetrievalApiImpl.h"
#include "UEContextInSMFDataRetrievalApiImpl.h"
#include "UEContextInSMSFDataRetrievalApiImpl.h"

#define PISTACHE_SERVER_THREADS     2
#define PISTACHE_SERVER_MAX_PAYLOAD 32768

static Pistache::Http::Endpoint *httpEndpoint;
#ifdef __linux__
static void sigHandler(int sig){
    switch(sig){
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
        case SIGHUP:
        default:
            httpEndpoint->shutdown();
            break;
    }
    exit(0);
}

static void setUpUnixSignals(std::vector<int> quitSignals) {
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

using namespace oai::udm::api;

int main(int argc, char* argv[]) {
#ifdef __linux__
    std::vector<int> sigs{SIGQUIT, SIGINT, SIGTERM, SIGHUP};
    setUpUnixSignals(sigs);
#endif
    std::string udm_ip_address;
    if ((argc != 1) && (argc != 3)) {
        std::cout << "Error: Usage is " <<std::endl;
        std::cout << "  " << argv[0] << " [ -i www.xxx.yy.zz ]" <<std::endl;
        return -1;
    }

    if (argc == 1) {
        udm_ip_address.append(std::string("192.168.28.4"));
    } else {
        int opt = 0;
        while ((opt = getopt(argc, argv, "i:")) != -1) {
            switch(opt) {
            case 'i':
                udm_ip_address.append(optarg);
                break;
            default:
                std::cout << "Error: Usage is " <<std::endl;
                std::cout << "  " << argv[0] << " [ -i www.xxx.yy.zz ]" <<std::endl;
                return -1;
                break;
            }
        }
    }

    Pistache::Address addr(udm_ip_address, Pistache::Port(80));

    httpEndpoint = new Pistache::Http::Endpoint((addr));
    auto router = std::make_shared<Pistache::Rest::Router>();

    auto opts = Pistache::Http::Endpoint::options()
        .threads(PISTACHE_SERVER_THREADS);
    opts.flags(Pistache::Tcp::Options::ReuseAddr);
    opts.maxPayload(PISTACHE_SERVER_MAX_PAYLOAD);
    httpEndpoint->init(opts);

    
    AccessAndMobilitySubscriptionDataRetrievalApiImpl AccessAndMobilitySubscriptionDataRetrievalApiserver(router);
    AccessAndMobilitySubscriptionDataRetrievalApiserver.init();
    GPSIToSUPITranslationApiImpl GPSIToSUPITranslationApiserver(router);
    GPSIToSUPITranslationApiserver.init();
    GroupIdentifiersApiImpl GroupIdentifiersApiserver(router);
    GroupIdentifiersApiserver.init();
    ProvidingAcknowledgementOfSteeringOfRoamingApiImpl ProvidingAcknowledgementOfSteeringOfRoamingApiserver(router);
    ProvidingAcknowledgementOfSteeringOfRoamingApiserver.init();
    ProvidingAcknowledgementOfUEParametersUpdateApiImpl ProvidingAcknowledgementOfUEParametersUpdateApiserver(router);
    ProvidingAcknowledgementOfUEParametersUpdateApiserver.init();
    RetrievalOfMultipleDataSetsApiImpl RetrievalOfMultipleDataSetsApiserver(router);
    RetrievalOfMultipleDataSetsApiserver.init();
    RetrievalOfSharedDataApiImpl RetrievalOfSharedDataApiserver(router);
    RetrievalOfSharedDataApiserver.init();
    SMFSelectionSubscriptionDataRetrievalApiImpl SMFSelectionSubscriptionDataRetrievalApiserver(router);
    SMFSelectionSubscriptionDataRetrievalApiserver.init();
    SMSManagementSubscriptionDataRetrievalApiImpl SMSManagementSubscriptionDataRetrievalApiserver(router);
    SMSManagementSubscriptionDataRetrievalApiserver.init();
    SMSSubscriptionDataRetrievalApiImpl SMSSubscriptionDataRetrievalApiserver(router);
    SMSSubscriptionDataRetrievalApiserver.init();
    SessionManagementSubscriptionDataRetrievalApiImpl SessionManagementSubscriptionDataRetrievalApiserver(router);
    SessionManagementSubscriptionDataRetrievalApiserver.init();
    SliceSelectionSubscriptionDataRetrievalApiImpl SliceSelectionSubscriptionDataRetrievalApiserver(router);
    SliceSelectionSubscriptionDataRetrievalApiserver.init();
    SubscriptionCreationApiImpl SubscriptionCreationApiserver(router);
    SubscriptionCreationApiserver.init();
    SubscriptionCreationForSharedDataApiImpl SubscriptionCreationForSharedDataApiserver(router);
    SubscriptionCreationForSharedDataApiserver.init();
    SubscriptionDeletionApiImpl SubscriptionDeletionApiserver(router);
    SubscriptionDeletionApiserver.init();
    SubscriptionDeletionForSharedDataApiImpl SubscriptionDeletionForSharedDataApiserver(router);
    SubscriptionDeletionForSharedDataApiserver.init();
    SubscriptionModificationApiImpl SubscriptionModificationApiserver(router);
    SubscriptionModificationApiserver.init();
    TraceConfigurationDataRetrievalApiImpl TraceConfigurationDataRetrievalApiserver(router);
    TraceConfigurationDataRetrievalApiserver.init();
    UEContextInSMFDataRetrievalApiImpl UEContextInSMFDataRetrievalApiserver(router);
    UEContextInSMFDataRetrievalApiserver.init();
    UEContextInSMSFDataRetrievalApiImpl UEContextInSMSFDataRetrievalApiserver(router);
    UEContextInSMSFDataRetrievalApiserver.init();

    httpEndpoint->setHandler(router->handler());
    httpEndpoint->serve();

    httpEndpoint->shutdown();

}

