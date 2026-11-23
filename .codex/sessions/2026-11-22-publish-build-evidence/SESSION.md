# Session: publish build evidence

## Objective

Finish publishing the real MARKI visual archive and the safely sanitized ESP32 LED and buzzer test sketch.

## Locations

- GIT container: `/Users/naveen/GIT`
- Repository: `/Users/naveen/marki-my-personal-desktop-part`
- Branch: `main`
- Overall project: `Marki`
- Aspect: `Publish documented build evidence`
- Hackatime project: `Marki — Publish documented build evidence`

## Changes

- Added the real build photos, Arduino screenshots, diagrams, and build reports.
- Added a source-controlled ESP32 controller sketch with the original private access-point password replaced by a placeholder.
- Added firmware, asset, and documentation links so the evidence is navigable from the repository homepage.

## Verification

- Confirmed `sync_ai_disabled = true` and the Hackatime API endpoint without reading the API key.
- Sent one normal coding heartbeat for the firmware file after its real edit, using the Marki project and this focused aspect.
- Confirmed the public sketch contains only `CHANGE_ME_BEFORE_UPLOAD`, not the original access-point password.
- `arduino-cli` is not installed in this environment, so a board-core compile could not be run here.
- Confirmed the 10 original build photos, 10 Arduino screenshots, 2 diagrams, and 2 build-report files have valid file types.
- `git diff --cached --check` passed with no whitespace errors.
- Pending: remote push.

## Artifact policy

This session folder is tracked because the repository had no existing ignore rule for `.codex/sessions`.
