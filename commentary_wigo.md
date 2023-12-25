Why - why a bootloop 'all of a sudden'

  fundamentally:  esp32 vs uno r4 - local compile was probably uno r4 only,
  whereas wokwi compile was esp32.

  the bootloop is basically trying to use wokwi.toml vscode wokwi extension
  on what was written for Uno R4 WiFi - too much to ask.

  Main problem was forgetting:  esp32 was used as a compromise **stand in**
  just to have something to work with in the wokwi context.

  Target all along was Uno R4 WiFi.

  In short: wokwi was never an option in the dev cycle the way the
  attempt was made today (24 Dec 2023, now 25) back quiet

TODO: see what compatibility can be coerced so that the above is
      a bit less true than 'now'.

Mon 25 Dec 02:01:55 UTC 2023
