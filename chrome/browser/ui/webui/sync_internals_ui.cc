// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/webui/sync_internals_ui.h"

#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/webui/sync_internals_message_handler.h"
#include "chrome/common/url_constants.h"
#include "components/sync/driver/about_sync_util.h"
#include "content/public/browser/web_ui.h"
#include "content/public/browser/web_ui_data_source.h"
#include "grit/components_resources.h"

namespace {

content::WebUIDataSource* CreateSyncInternalsHTMLSource() {
  content::WebUIDataSource* source =
      content::WebUIDataSource::Create(chrome::kChromeUISyncInternalsHost);

  source->SetJsonPath("strings.js");
  source->AddResourcePath(sync_driver::sync_ui_util::kSyncIndexJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_INDEX_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kChromeSyncJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_CHROME_SYNC_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kTypesJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_TYPES_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kSyncLogJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_SYNC_LOG_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kSyncNodeBrowserJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_SYNC_NODE_BROWSER_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kSyncSearchJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_SYNC_SEARCH_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kAboutJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_ABOUT_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kDataJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_DATA_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kEventsJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_EVENTS_JS);
  source->AddResourcePath(sync_driver::sync_ui_util::kSearchJS,
                          IDR_SYNC_DRIVER_SYNC_INTERNALS_SEARCH_JS);
  source->SetDefaultResource(IDR_SYNC_DRIVER_SYNC_INTERNALS_INDEX_HTML);
  return source;
}

}  // namespace

SyncInternalsUI::SyncInternalsUI(content::WebUI* web_ui)
    : WebUIController(web_ui) {
  Profile* profile = Profile::FromWebUI(web_ui);
  content::WebUIDataSource::Add(profile, CreateSyncInternalsHTMLSource());

  web_ui->AddMessageHandler(new SyncInternalsMessageHandler);
}

SyncInternalsUI::~SyncInternalsUI() {}

