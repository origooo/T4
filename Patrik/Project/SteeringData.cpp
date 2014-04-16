/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifdef PANDABOARD
#include <stdc-predef.h>
#endif

#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"

#include "SteeringData.h"

namespace msv {

	using namespace std;
	using namespace core::base;

	SteeringData::SteeringData() : 
        steeringAngle(0),
        leftLineDistance(0),
        centerDistance(0),
        leftLineAngle(0),
        stopLineDetected(false) {}

	SteeringData::SteeringData(const SteeringData &obj) :
	    SerializableData(),
        steeringAngle(obj.steeringAngle),
        leftLineDistance(obj.leftLineDistance),
        centerDistance(obj.centerDistance),
        leftLineAngle(obj.leftLineAngle),
        stopLineDetected(obj.stopLineDetected) {}

	SteeringData::~SteeringData() {}

	SteeringData& SteeringData::operator=(const SteeringData &obj) {
        steeringAngle = obj.steeringAngle;
        leftLineDistance = obj.leftLineDistance;
        centerDistance = obj.centerDistance;
        leftLineAngle = obj.leftLineAngle;
        stopLineDetected = obj.stopLineDetected;

		return (*this);
	}

    double SteeringData::getSteeringAngle() const {
        return steeringAngle;
    }

    void SteeringData::setSteeringAngle(const double &e) {
        steeringAngle = e;
    }

    double SteeringData::getLeftLineDistance() const {
        return leftLineDistance;
    }

    void SteeringData::setLeftLineDistance(const double &ld) {
    	leftLineDistance = ld;
    }

    double SteeringData::getCenterDistance() const {
        return centerDistance;
    }

    void SteeringData::setCenterDistance(const double &cd) {
    	centerDistance = cd;
    }

    double SteeringData::getLeftLineAngle() const {
        return leftLineAngle;
    }

    void SteeringData::setLeftLineAngle(const double &la) {
    	leftLineAngle = la;
    }

    bool SteeringData::getStopLineDetected() const {
    	return stopLineDetected;
    }
    void SteeringData::setStopLineDetected(const bool &sld) {
    	stopLineDetected = sld;
    }

	const string SteeringData::toString() const {
		stringstream s;

        s << "Angle from LD: " << getSteeringAngle();

		return s.str();
	}

	ostream& SteeringData::operator<<(ostream &out) const {
		SerializationFactory sf;

		Serializer &s = sf.getSerializer(out);

		s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('s', 't', 'e', 'e', 'r', 'i', 'n', 'g') >::RESULT,steeringAngle);
		s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('l', 'e', 'f', 't', 'd', 'i', 's', 't') >::RESULT,leftLineDistance);
		s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('c', 'e', 'n', 't', 'e', 'r', 'd', 'i') >::RESULT,centerDistance);
		s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('l', 'e', 'f', 't', 'a', 'n', 'g', 'l') >::RESULT,leftLineAngle);
		s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('s', 't', 'o', 'p', 'l', 'i', 'n', 'e') >::RESULT,stopLineDetected);

		return out;
	}

	istream& SteeringData::operator>>(istream &in) {
		SerializationFactory sf;

		Deserializer &d = sf.getDeserializer(in);

		d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('s', 't', 'e', 'e', 'r', 'i', 'n', 'g') >::RESULT,steeringAngle);
		d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('l', 'e', 'f', 't', 'd', 'i', 's', 't') >::RESULT,leftLineDistance);
		d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('c', 'e', 'n', 't', 'e', 'r', 'd', 'i') >::RESULT,centerDistance);
		d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('l', 'e', 'f', 't', 'a', 'n', 'g', 'l') >::RESULT,leftLineAngle);
		d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL8('s', 't', 'o', 'p', 'l', 'i', 'n', 'e') >::RESULT,stopLineDetected);

		return in;
	}

} // msv

