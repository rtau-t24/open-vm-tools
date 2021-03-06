/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/DiagTypesXml/DiagDeleteValueXml.h"

#include "Doc/DiagTypesDoc/CDiagDeleteValueCollectionDoc.h"
#include "Doc/DiagTypesDoc/CDiagDeleteValueDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/DiagTypesXml/DiagDeleteValueCollectionXml.h"

using namespace Caf;

void DiagDeleteValueCollectionXml::add(
	const SmartPtrCDiagDeleteValueCollectionDoc diagDeleteValueCollectionDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagDeleteValueCollectionXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(diagDeleteValueCollectionDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::deque<SmartPtrCDiagDeleteValueDoc> deleteValueVal =
			diagDeleteValueCollectionDoc->getDeleteValueCollection();
		CAF_CM_VALIDATE_STL(deleteValueVal);

		if (! deleteValueVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCDiagDeleteValueDoc> > deleteValueIter(deleteValueVal);
				deleteValueIter; deleteValueIter++) {
				const SmartPtrCXmlElement deleteValueXml =
					thisXml->createAndAddElement("deleteValue");
				DiagDeleteValueXml::add(*deleteValueIter, deleteValueXml);
			}
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCDiagDeleteValueCollectionDoc DiagDeleteValueCollectionXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagDeleteValueCollectionXml", "parse");

	SmartPtrCDiagDeleteValueCollectionDoc diagDeleteValueCollectionDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const CXmlElement::SmartPtrCElementCollection deleteValueChildrenXml =
			thisXml->findRequiredChildren("deleteValue");

		std::deque<SmartPtrCDiagDeleteValueDoc> deleteValueVal;
		if (! deleteValueChildrenXml.IsNull() && ! deleteValueChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> deleteValueXmlIter(*deleteValueChildrenXml);
				deleteValueXmlIter; deleteValueXmlIter++) {
				const SmartPtrCXmlElement deleteValueXml = deleteValueXmlIter->second;
				const SmartPtrCDiagDeleteValueDoc deleteValueDoc =
					DiagDeleteValueXml::parse(deleteValueXml);
				deleteValueVal.push_back(deleteValueDoc);
			}
		}

		diagDeleteValueCollectionDoc.CreateInstance();
		diagDeleteValueCollectionDoc->initialize(
			deleteValueVal);
	}
	CAF_CM_EXIT;

	return diagDeleteValueCollectionDoc;
}

