/* jshint asi:true */

var InstallComponents = [
	"qt.qt5.5142.win32_mingw73",
	"qt.tools.win32_mingw730",
];

var InstallPath = "c:\\Qt";

// Public domain via CC0.

function Controller() {
    installer.autoRejectMessageBoxes();
    installer.installationFinished.connect(proceed);
}

function logCurrentPage() {
    var pageName = page().objectName
    var pagePrettyTitle = page().title
    console.log("At page: " + pageName + " ('" + pagePrettyTitle + "')")
}

function page() {
    return gui.currentPageWidget()
}

function proceed(button, delay) {
    gui.clickButton(button || buttons.NextButton, delay)
}

/// Skip welcome page
Controller.prototype.WelcomePageCallback = function() {
    logCurrentPage()
    // For some reason, delay is needed.  Two seconds seems to be enough.
    proceed(buttons.NextButton, 2000)
}

/// Just click next -- that is sign in to Qt account if credentials are
/// remembered from previous installs, or skip sign in otherwise.
Controller.prototype.CredentialsPageCallback = function() {
    logCurrentPage()
    proceed()
}

/// Check "I have read and approve..." introduction page
Controller.prototype.ObligationsPageCallback = function() {
    logCurrentPage()
    page().obligationsAgreement.setChecked(true);
    page().completeChanged();
    proceed()
}

/// Skip introduction page
Controller.prototype.IntroductionPageCallback = function() {
    logCurrentPage()
    proceed(buttons.NextButton, 2000)
}

/// Question for tracking usage data, refuse it
Controller.prototype.DynamicTelemetryPluginFormCallback = function() {
    logCurrentPage()
    var radioButtons = page().TelemetryPluginForm.statisticGroupBox
    radioButtons.disableStatisticRadioButton.checked = true
    proceed()
}

/// Set target directory
Controller.prototype.TargetDirectoryPageCallback = function() {
    logCurrentPage()
    page().TargetDirectoryLineEdit.setText(InstallPath)
    proceed(buttons.NextButton, 2000);
}

Controller.prototype.ComponentSelectionPageCallback = function() {
    logCurrentPage()
    // Deselect whatever was default, and can be deselected.
    page().deselectAll()

    InstallComponents.forEach(function(component) {
        page().selectComponent(component)
    })

    proceed()
}

/// Agree license
Controller.prototype.LicenseAgreementPageCallback = function() {
    logCurrentPage()
    page().AcceptLicenseRadioButton.checked = true
    proceed()
}

/// Windows-specific, skip it
Controller.prototype.StartMenuDirectoryPageCallback = function() {
    logCurrentPage()
    proceed()
}

/// Skip confirmation page
Controller.prototype.ReadyForInstallationPageCallback = function() {
    logCurrentPage()
    proceed()
}

/// Installation in progress, do nothing
Controller.prototype.PerformInstallationPageCallback = function() {
    logCurrentPage()
}

Controller.prototype.FinishedPageCallback = function() {
    logCurrentPage()
    // Deselect "launch QtCreator"
    page().LaunchQtCreatorCheckBoxForm.launchQtCreatorCheckBox.setChecked(false);
    proceed(buttons.FinishButton, 0);
}
