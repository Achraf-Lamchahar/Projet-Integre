-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : mar. 10 jan. 2023 à 03:30
-- Version du serveur : 10.4.27-MariaDB
-- Version de PHP : 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `traindatabase`
--

-- --------------------------------------------------------

--
-- Structure de la table `ticket`
--

CREATE TABLE `ticket` (
  `noTicket` int(8) NOT NULL,
  `NomPrenom` varchar(30) NOT NULL,
  `villeDepart` varchar(20) NOT NULL,
  `villeArrive` varchar(20) NOT NULL,
  `dateDepart` varchar(12) NOT NULL,
  `horaireDepart` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `ticket`
--

INSERT INTO `ticket` (`noTicket`, `NomPrenom`, `villeDepart`, `villeArrive`, `dateDepart`, `horaireDepart`) VALUES
(3, 'DEROUICH KARIM', 'Rabat', 'Casablanca', '2023-01-04', '11:00'),
(4, 'ACHRAF LAMCHAHAR', 'RABAT', 'CASABLANCA', '2023-01-11', '12:00');

-- --------------------------------------------------------

--
-- Structure de la table `titres`
--

CREATE TABLE `titres` (
  `idTitre` varchar(20) NOT NULL,
  `NomPrenom` varchar(30) NOT NULL,
  `villeDepart` varchar(20) NOT NULL,
  `villeArrive` varchar(20) NOT NULL,
  `nbUtlisations` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `titres`
--

INSERT INTO `titres` (`idTitre`, `NomPrenom`, `villeDepart`, `villeArrive`, `nbUtlisations`) VALUES
('20230109BM', 'MEHDI BOUKHOBZA', 'RABAT', 'FES', 0),
('20230109EM', 'MOAD ELMARDI', 'RABAT', 'TANGER', 0),
('20230109KZ', 'ZYAD KHALEF', 'RABAT', 'MARRAKECH', 0),
('20230109LA', 'ACHRAF LAMCHAHAR', 'RABAT', 'CASABLANCA', 0),
('20230110BA', 'AYMAN BELHAJ', 'RABAT', 'TAMESNA', 0),
('20230110BI', 'IHAB BOKAL', 'RABAT', 'TANGER', 0),
('20230110DK', 'DEROUICH KARIM', 'RABAT', 'AGADIR', 0),
('20230110JS', 'SALAHEDDINE JOUHAINI', 'SALE', 'MEKNES', 0);

-- --------------------------------------------------------

--
-- Structure de la table `train`
--

CREATE TABLE `train` (
  `idTrain` varchar(20) NOT NULL,
  `nomTrain` varchar(20) NOT NULL,
  `nbPlacesMax` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `train`
--

INSERT INTO `train` (`idTrain`, `nomTrain`, `nbPlacesMax`) VALUES
('A1000', 'ATLAS', 350),
('A1234', 'ALBORAQ', 480),
('A1478', 'ALBORAQ', 510),
('A2001', 'ATLAS', 500),
('A3500', 'ATLAS', 400),
('A3698', 'ALBORAQ', 500),
('A8956', 'ATLAS', 520),
('T1001', 'TLR', 300),
('T2000', 'TN', 180),
('T2023', 'TLR', 480),
('T2314', 'TN', 310),
('T3210', 'TN', 340);

-- --------------------------------------------------------

--
-- Structure de la table `trajets`
--

CREATE TABLE `trajets` (
  `idTrain` varchar(20) NOT NULL,
  `villeDepart` varchar(20) NOT NULL,
  `villeArrive` varchar(20) NOT NULL,
  `dateDepart` varchar(10) NOT NULL,
  `horaireDepart` varchar(10) NOT NULL,
  `horaireArrive` varchar(10) NOT NULL,
  `prix` float NOT NULL,
  `placesReserves` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `trajets`
--

INSERT INTO `trajets` (`idTrain`, `villeDepart`, `villeArrive`, `dateDepart`, `horaireDepart`, `horaireArrive`, `prix`, `placesReserves`) VALUES
('A1000', 'RABAT', 'CASABLANCA', '2023-01-11', '11:00', '12:00', 42, 5),
('A1001', 'RABAT', 'MARRAKECH', '2023-01-10', '18:00', '22:00', 190, 6),
('A1234', 'RABAT', 'TANGER', '2023-01-13', '08:30', '10:00', 120, 7),
('A2001', 'RABAT', 'FES', '2023-01-11', '12:00', '14:00', 150, 8),
('A8956', 'RABAT', 'AGADIR', '2023-01-10', '21:00', '07:00', 150, 9),
('T2000', 'RABAT', 'CASABLANCA', '2023-01-14', '17:20', '18:10', 38, 10);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`noTicket`);

--
-- Index pour la table `titres`
--
ALTER TABLE `titres`
  ADD PRIMARY KEY (`idTitre`);

--
-- Index pour la table `train`
--
ALTER TABLE `train`
  ADD PRIMARY KEY (`idTrain`);

--
-- Index pour la table `trajets`
--
ALTER TABLE `trajets`
  ADD PRIMARY KEY (`placesReserves`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `ticket`
--
ALTER TABLE `ticket`
  MODIFY `noTicket` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `trajets`
--
ALTER TABLE `trajets`
  MODIFY `placesReserves` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
