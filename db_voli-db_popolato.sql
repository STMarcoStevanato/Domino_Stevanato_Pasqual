-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Creato il: Mag 23, 2023 alle 17:24
-- Versione del server: 8.0.30
-- Versione PHP: 8.1.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_voli`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `airports`
--

CREATE TABLE `airports` (
  `code` varchar(3) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `name` varchar(200) CHARACTER SET utf8mb3 COLLATE utf8mb3_turkish_ci DEFAULT NULL,
  `cityName` varchar(200) CHARACTER SET utf8mb3 COLLATE utf8mb3_turkish_ci DEFAULT NULL,
  `countryName` varchar(200) CHARACTER SET utf8mb3 COLLATE utf8mb3_turkish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_turkish_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `bagagli`
--

CREATE TABLE `bagagli` (
  `bagaglio_id` int NOT NULL,
  `tipo_id` int NOT NULL,
  `quantita` int NOT NULL,
  `costo` double(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `biglietti`
--

CREATE TABLE `biglietti` (
  `biglietto_id` int NOT NULL,
  `codice_volo` varchar(8) DEFAULT NULL,
  `compagnia_aerea` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `classi`
--

CREATE TABLE `classi` (
  `classe_id` int NOT NULL,
  `nome_classe` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `frequenza_voli`
--

CREATE TABLE `frequenza_voli` (
  `frequenza_id` int NOT NULL,
  `codice_volo` varchar(8) NOT NULL,
  `inizio_periodo` date NOT NULL,
  `fine_periodo` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `giorni`
--

CREATE TABLE `giorni` (
  `giorno_id` int NOT NULL,
  `nome` varchar(9) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `passeggeri`
--

CREATE TABLE `passeggeri` (
  `passeggero_id` int NOT NULL,
  `prenotazione_id` int NOT NULL,
  `posto_id` int NOT NULL,
  `sesso_id` int NOT NULL,
  `nome` varchar(30) NOT NULL,
  `cognome` varchar(30) NOT NULL,
  `email` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `passeggeri_bagagli`
--

CREATE TABLE `passeggeri_bagagli` (
  `passeggero_id` int NOT NULL,
  `bagagli_id` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `periodi_giorni`
--

CREATE TABLE `periodi_giorni` (
  `frequenza_id` int NOT NULL,
  `giorno_id` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `posti`
--

CREATE TABLE `posti` (
  `posto_id` int NOT NULL,
  `codice_volo` varchar(8) DEFAULT NULL,
  `classe_id` int NOT NULL,
  `nome` varchar(3) NOT NULL,
  `disponibile` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `prenotazioni`
--

CREATE TABLE `prenotazioni` (
  `prenotazione_id` int NOT NULL,
  `biglietto_id` int NOT NULL,
  `utente_id` int NOT NULL,
  `costo` decimal(10,2) NOT NULL,
  `data_prenotazione` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `sesso`
--

CREATE TABLE `sesso` (
  `sesso_id` int NOT NULL,
  `sesso` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `tipologia_bagagli`
--

CREATE TABLE `tipologia_bagagli` (
  `tipo_id` int NOT NULL,
  `nome` varchar(20) NOT NULL,
  `altezza` double(10,2) NOT NULL,
  `lunghezza` double(10,2) NOT NULL,
  `larghezza` double(10,2) NOT NULL,
  `peso` double(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `utenti`
--

CREATE TABLE `utenti` (
  `utente_id` int NOT NULL,
  `nome` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT NULL,
  `cognome` varchar(30) NOT NULL,
  `email` varchar(30) DEFAULT NULL,
  `numero_telefono` varchar(30) DEFAULT NULL,
  `data_nascita` date DEFAULT NULL,
  `password` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `utente_creato_a` datetime NOT NULL,
  `utente_modificato_a` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Struttura della tabella `voli`
--

CREATE TABLE `voli` (
  `codice_volo` varchar(8) NOT NULL,
  `ora_partenza` time NOT NULL,
  `posti_disponibili` int DEFAULT NULL,
  `ora_arrivo` time NOT NULL,
  `codice_aeroporto_partenza` varchar(3) NOT NULL,
  `codice_aeroporto_arrivo` varchar(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `airports`
--
ALTER TABLE `airports`
  ADD PRIMARY KEY (`code`);

--
-- Indici per le tabelle `bagagli`
--
ALTER TABLE `bagagli`
  ADD PRIMARY KEY (`bagaglio_id`),
  ADD KEY `tipo_id` (`tipo_id`);

--
-- Indici per le tabelle `biglietti`
--
ALTER TABLE `biglietti`
  ADD PRIMARY KEY (`biglietto_id`),
  ADD KEY `codice_volo` (`codice_volo`);

--
-- Indici per le tabelle `classi`
--
ALTER TABLE `classi`
  ADD PRIMARY KEY (`classe_id`);

--
-- Indici per le tabelle `frequenza_voli`
--
ALTER TABLE `frequenza_voli`
  ADD PRIMARY KEY (`frequenza_id`),
  ADD KEY `codice_volo` (`codice_volo`);

--
-- Indici per le tabelle `giorni`
--
ALTER TABLE `giorni`
  ADD PRIMARY KEY (`giorno_id`);

--
-- Indici per le tabelle `passeggeri`
--
ALTER TABLE `passeggeri`
  ADD PRIMARY KEY (`passeggero_id`),
  ADD KEY `prenotazione` (`prenotazione_id`),
  ADD KEY `sesso_id` (`sesso_id`),
  ADD KEY `posto_id` (`posto_id`);

--
-- Indici per le tabelle `passeggeri_bagagli`
--
ALTER TABLE `passeggeri_bagagli`
  ADD PRIMARY KEY (`passeggero_id`,`bagagli_id`),
  ADD KEY `bagagli_id` (`bagagli_id`);

--
-- Indici per le tabelle `periodi_giorni`
--
ALTER TABLE `periodi_giorni`
  ADD PRIMARY KEY (`frequenza_id`,`giorno_id`),
  ADD KEY `giorno_id` (`giorno_id`);

--
-- Indici per le tabelle `posti`
--
ALTER TABLE `posti`
  ADD PRIMARY KEY (`posto_id`),
  ADD KEY `codice_volo` (`codice_volo`),
  ADD KEY `classe_id` (`classe_id`);

--
-- Indici per le tabelle `prenotazioni`
--
ALTER TABLE `prenotazioni`
  ADD PRIMARY KEY (`prenotazione_id`),
  ADD KEY `utente_id` (`utente_id`),
  ADD KEY `biglietto_id` (`biglietto_id`);

--
-- Indici per le tabelle `sesso`
--
ALTER TABLE `sesso`
  ADD PRIMARY KEY (`sesso_id`);

--
-- Indici per le tabelle `tipologia_bagagli`
--
ALTER TABLE `tipologia_bagagli`
  ADD PRIMARY KEY (`tipo_id`);

--
-- Indici per le tabelle `utenti`
--
ALTER TABLE `utenti`
  ADD PRIMARY KEY (`utente_id`);

--
-- Indici per le tabelle `voli`
--
ALTER TABLE `voli`
  ADD PRIMARY KEY (`codice_volo`),
  ADD KEY `codice_aeroporto_partenza` (`codice_aeroporto_partenza`),
  ADD KEY `codice_aeroporto_arrivo` (`codice_aeroporto_arrivo`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `classi`
--
ALTER TABLE `classi`
  MODIFY `classe_id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `frequenza_voli`
--
ALTER TABLE `frequenza_voli`
  MODIFY `frequenza_id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `passeggeri`
--
ALTER TABLE `passeggeri`
  MODIFY `passeggero_id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `sesso`
--
ALTER TABLE `sesso`
  MODIFY `sesso_id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `tipologia_bagagli`
--
ALTER TABLE `tipologia_bagagli`
  MODIFY `tipo_id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `utenti`
--
ALTER TABLE `utenti`
  MODIFY `utente_id` int NOT NULL AUTO_INCREMENT;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `bagagli`
--
ALTER TABLE `bagagli`
  ADD CONSTRAINT `bagagli_ibfk_1` FOREIGN KEY (`tipo_id`) REFERENCES `tipologia_bagagli` (`tipo_id`);

--
-- Limiti per la tabella `frequenza_voli`
--
ALTER TABLE `frequenza_voli`
  ADD CONSTRAINT `frequenza_voli_ibfk_1` FOREIGN KEY (`codice_volo`) REFERENCES `voli` (`codice_volo`),
  ADD CONSTRAINT `frequenza_voli_ibfk_2` FOREIGN KEY (`frequenza_id`) REFERENCES `periodi_giorni` (`frequenza_id`);

--
-- Limiti per la tabella `passeggeri`
--
ALTER TABLE `passeggeri`
  ADD CONSTRAINT `passeggeri_ibfk_1` FOREIGN KEY (`sesso_id`) REFERENCES `sesso` (`sesso_id`),
  ADD CONSTRAINT `passeggeri_ibfk_2` FOREIGN KEY (`prenotazione_id`) REFERENCES `prenotazioni` (`prenotazione_id`);

--
-- Limiti per la tabella `passeggeri_bagagli`
--
ALTER TABLE `passeggeri_bagagli`
  ADD CONSTRAINT `passeggeri_bagagli_ibfk_1` FOREIGN KEY (`passeggero_id`) REFERENCES `passeggeri` (`passeggero_id`),
  ADD CONSTRAINT `passeggeri_bagagli_ibfk_2` FOREIGN KEY (`bagagli_id`) REFERENCES `bagagli` (`bagaglio_id`);

--
-- Limiti per la tabella `periodi_giorni`
--
ALTER TABLE `periodi_giorni`
  ADD CONSTRAINT `periodi_giorni_ibfk_1` FOREIGN KEY (`giorno_id`) REFERENCES `giorni` (`giorno_id`),
  ADD CONSTRAINT `periodi_giorni_ibfk_2` FOREIGN KEY (`giorno_id`) REFERENCES `giorni` (`giorno_id`);

--
-- Limiti per la tabella `posti`
--
ALTER TABLE `posti`
  ADD CONSTRAINT `posti_ibfk_1` FOREIGN KEY (`codice_volo`) REFERENCES `voli` (`codice_volo`),
  ADD CONSTRAINT `posti_ibfk_2` FOREIGN KEY (`classe_id`) REFERENCES `classi` (`classe_id`);

--
-- Limiti per la tabella `prenotazioni`
--
ALTER TABLE `prenotazioni`
  ADD CONSTRAINT `prenotazioni_ibfk_3` FOREIGN KEY (`biglietto_id`) REFERENCES `biglietti` (`biglietto_id`),
  ADD CONSTRAINT `prenotazioni_ibfk_4` FOREIGN KEY (`utente_id`) REFERENCES `utenti` (`utente_id`);

--
-- Limiti per la tabella `voli`
--
ALTER TABLE `voli`
  ADD CONSTRAINT `voli_ibfk_1` FOREIGN KEY (`codice_volo`) REFERENCES `biglietti` (`codice_volo`),
  ADD CONSTRAINT `voli_ibfk_2` FOREIGN KEY (`codice_aeroporto_partenza`) REFERENCES `airports` (`code`),
  ADD CONSTRAINT `voli_ibfk_3` FOREIGN KEY (`codice_aeroporto_arrivo`) REFERENCES `airports` (`code`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
